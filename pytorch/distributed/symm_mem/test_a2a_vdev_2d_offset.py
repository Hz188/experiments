import torch
import torch.distributed as dist
import torch.distributed._symmetric_memory as symm_mem

# Initialize distributed environment
dist.init_process_group("nccl")

rank = dist.get_rank()
world_size = dist.get_world_size()
torch.cuda.set_device(f"cuda:{rank}")

# Setup symmetric memory backend
symm_mem.set_backend("NVSHMEM")
# symm_mem.set_backend("CUDA")
group_name = dist.group.WORLD.group_name
symm_mem.enable_symm_mem_for_group(group_name)

# Test parameters for 2D all-to-all with offset
ne = 2  # number of experts per rank
total_experts = world_size * ne  # total number of experts

# Define data splits for each expert on each rank
# For combine operation: each rank has data for all experts, arranged in expert-major order
# expert_chunk_sizes[rank][expert_id] = how much data 'rank' has for 'expert_id'
expert_chunk_sizes = [
    [5, 3, 7, 2],  # Rank 0: 5 for expert 0, 3 for expert 1, 7 for expert 2, 2 for expert 3
    [4, 6, 1, 8]   # Rank 1: 4 for expert 0, 6 for expert 1, 1 for expert 2, 8 for expert 3
]

# For combine operation, the input layout should be expert-major order
# Each rank has data for all experts, arranged by expert ID
# expert_chunk_sizes[rank][expert_id] = how much data 'rank' processed for 'expert_id'

# Define padding between chunks for each rank
expert_chunk_paddings = [
    [2, 1, 3, 0],  # Rank 0: 2 padding after expert 0, 1 after expert 1, 3 after expert 2, 0 after expert 3
    [1, 2, 0, 1]   # Rank 1: 1 padding after expert 0, 2 after expert 1, 0 after expert 2, 1 after expert 3
]

# Calculate total input size for this rank (including padding)
input_size = 0
input_offsets = []  # Starting offset for each expert in input tensor
current_offset = 0

for expert_id in range(total_experts):
    input_offsets.append(current_offset)
    chunk_size = expert_chunk_sizes[rank][expert_id]
    padding = expert_chunk_paddings[rank][expert_id]
    input_size += chunk_size + padding
    current_offset += chunk_size + padding

print(f"Rank {rank}: Input size = {input_size} (including padding)")

# Create input tensor with rank-specific data for each expert (including padding)
input_tensor = symm_mem.empty(input_size, dtype=torch.float32, device=f"cuda:{rank}")

# Fill input tensor with distinct values for each expert chunk
for expert_id in range(total_experts):
    chunk_size = expert_chunk_sizes[rank][expert_id]
    offset = input_offsets[expert_id]
    # Use a unique value for each expert chunk: rank * 100 + expert_id
    fill_value = float(rank * 100 + expert_id)
    input_tensor[offset:offset+chunk_size].fill_(fill_value)
    # Padding area remains as is (will not be transferred)

print(f"Rank {rank}: Input tensor = {input_tensor}")

# Calculate output size for this rank
# For combine operation: each rank collects data for its local experts from all ranks
output_size = 0
for expert_id in range(total_experts):
    expert_rank = expert_id % ne  # Which rank owns this expert
    if expert_rank == rank:  # This expert belongs to this rank
        # Sum up data for this expert from all ranks
        for src_rank in range(world_size):
            output_size += expert_chunk_sizes[src_rank][expert_id]

print(f"Rank {rank}: Output size = {output_size}")

# Create output tensor
output_tensor = symm_mem.empty(output_size, dtype=torch.float32, device=f"cuda:{rank}")

# Setup input splits and offsets - how much data this rank sends to each expert
in_splits_offsets = symm_mem.empty((2, total_experts), dtype=torch.int64, device=f"cuda:{rank}")

# Fill input splits and offsets
for expert_id in range(total_experts):
    in_splits_offsets[0, expert_id] = expert_chunk_sizes[rank][expert_id]  # splits
    in_splits_offsets[1, expert_id] = input_offsets[expert_id]  # offsets

# Setup output splits and offsets
out_splits_offsets = symm_mem.empty((2, total_experts), dtype=torch.int64, device=f"cuda:{rank}")

# Calculate how much data this rank receives for each expert
output_splits = []
output_offsets = []
current_offset = 0

for expert_id in range(total_experts):
    expert_rank = expert_id // ne  # Which rank owns this expert
    if expert_rank == rank:  # This expert belongs to this rank
        # Sum up data for this expert from all ranks
        total_for_expert = 0
        for src_rank in range(world_size):
            total_for_expert += expert_chunk_sizes[src_rank][expert_id]
        output_splits.append(total_for_expert)
        output_offsets.append(current_offset)
        current_offset += total_for_expert
    else:
        output_splits.append(0)
        output_offsets.append(0)

out_splits_offsets[0].copy_(torch.tensor(output_splits, dtype=torch.int64, device=f"cuda:{rank}"))
out_splits_offsets[1].copy_(torch.tensor(output_offsets, dtype=torch.int64, device=f"cuda:{rank}"))

print(f"Rank {rank}:")
print(f"  Input splits (to experts): {in_splits_offsets[0]}")
print(f"  Input offsets: {in_splits_offsets[1]}")
print(f"  Output splits (from experts): {out_splits_offsets[0]}")
print(f"  Output offsets: {out_splits_offsets[1]}")


# Perform 2D all-to-all-v operation with offset
print(f"Rank {rank}: Performing 2D all-to-all-v with offset...")
torch.ops.symm_mem.all_to_all_vdev_2d_offset(input_tensor, output_tensor, in_splits_offsets, out_splits_offsets, group_name)

print(f"Rank {rank}: Output tensor = {output_tensor}")

# Verify results
torch.cuda.synchronize()

# Expected output: expert-major order
# For rank 0 (experts 0,1,2,3): [e0_r0, e1_r0, e2_r0, e3_r0]
# For rank 1 (experts 0,1,2,3): [e0_r1, e1_r1, e2_r1, e3_r1]
# Note: padding should not be transferred

expected_output = []
for src_rank in range(world_size):
    for expert_id in range(total_experts):
        expert_rank: int = expert_id % ne
        if expert_rank == rank:  # This expert belongs to this rank
            # Collect data for this expert from all ranks
            chunk_size = expert_chunk_sizes[src_rank][expert_id]
            if chunk_size > 0:
                fill_value = float(src_rank * 100 + expert_id)
                expected_output.extend([fill_value] * chunk_size)

expected_output = torch.tensor(expected_output, dtype=torch.float32, device=f"cuda:{rank}")

print(f"Rank {rank}: Expected output = {expected_output}")
print(f"Rank {rank}: Output matches expected: {torch.allclose(output_tensor, expected_output, atol=1e-5)}")

assert torch.allclose(output_tensor, expected_output, atol=1e-5), f"Rank {rank} output mismatch"

print(f"Rank {rank}: 2D all-to-all-v with offset test PASSED!")


# torchrun --standalone --nnodes=1 --nproc-per-node=2 test_a2a_vdev_2d_offset.py