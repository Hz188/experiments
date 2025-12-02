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
group_name = dist.group.WORLD.group_name
symm_mem.enable_symm_mem_for_group(group_name)

# Test parameters for 2D all-to-all
ne = 2  # number of experts per rank
total_experts = world_size * ne  # total number of experts

# Define data splits for each expert on each rank
# Each rank has data for all experts, arranged in rank-major order
# Example for world_size=2, ne=2:
# Rank 0: [c0, c1, c2, c3] where c0,c1 are for rank 0's experts, c2,c3 are for rank 1's experts
# Rank 1: [d0, d1, d2, d3] where d0,d1 are for rank 0's experts, d2,d3 are for rank 1's experts

# Define the size of each expert chunk (in elements)
# This represents how much data each rank has for each expert
expert_chunk_sizes = [
    [5, 3, 7, 2],  # Rank 0: 5 for expert 0, 3 for expert 1, 7 for expert 2, 2 for expert 3
    [4, 6, 1, 8]   # Rank 1: 4 for expert 0, 6 for expert 1, 1 for expert 2, 8 for expert 3
]

# Calculate total input size for this rank
input_size = sum(expert_chunk_sizes[rank])
print(f"Rank {rank}: Input size = {input_size}")

# Create input tensor with rank-specific data for each expert
input_tensor = symm_mem.empty(input_size, dtype=torch.float32, device=f"cuda:{rank}")

# Fill input tensor with distinct values for each expert chunk
offset = 0
for expert_id in range(total_experts):
    chunk_size = expert_chunk_sizes[rank][expert_id]
    # Use a unique value for each expert chunk: rank * 100 + expert_id
    fill_value = float(rank * 100 + expert_id)
    input_tensor[offset:offset+chunk_size].fill_(fill_value)
    offset += chunk_size

print(f"Rank {rank}: Input tensor = {input_tensor}")

# Calculate output size for this rank
# After 2D shuffle, each rank receives data for its local experts from all ranks
output_size = 0
for expert_id in range(total_experts):
    expert_rank = expert_id // ne  # Which rank owns this expert
    if expert_rank == rank:  # This expert belongs to this rank
        # Sum up data for this expert from all ranks
        for src_rank in range(world_size):
            output_size += expert_chunk_sizes[src_rank][expert_id]

print(f"Rank {rank}: Output size = {output_size}")

# Create output tensor
output_tensor = symm_mem.empty(output_size, dtype=torch.float32, device=f"cuda:{rank}")

# Setup input splits - how much data this rank sends to each expert
in_splits = symm_mem.empty(total_experts, dtype=torch.int64, device=f"cuda:{rank}")
in_splits.copy_(torch.tensor(expert_chunk_sizes[rank], dtype=torch.int64, device=f"cuda:{rank}"))

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
print(f"  Input splits (to experts): {in_splits}")
print(f"  Output splits (from experts): {out_splits_offsets[0]}")
print(f"  Output offsets: {out_splits_offsets[1]}")

# Perform 2D all-to-all-v operation
print(f"Rank {rank}: Performing 2D all-to-all-v...")
torch.ops.symm_mem.all_to_all_vdev_2d(input_tensor, output_tensor, in_splits, out_splits_offsets, group_name)

print(f"Rank {rank}: Output tensor = {output_tensor}")

# Verify results
torch.cuda.synchronize()

# Expected output: expert-major order
# For rank 0 (experts 0,1): [c0, d0, c1, d1]
# For rank 1 (experts 2,3): [c2, d2, c3, d3]

expected_output = []
for expert_id in range(total_experts):
    expert_rank = expert_id // ne
    if expert_rank == rank:  # This expert belongs to this rank
        # Collect data for this expert from all ranks
        for src_rank in range(world_size):
            chunk_size = expert_chunk_sizes[src_rank][expert_id]
            if chunk_size > 0:
                fill_value = float(src_rank * 100 + expert_id)
                expected_output.extend([fill_value] * chunk_size)

expected_output = torch.tensor(expected_output, dtype=torch.float32, device=f"cuda:{rank}")

print(f"Rank {rank}: Expected output = {expected_output}")
print(f"Rank {rank}: Output matches expected: {torch.allclose(output_tensor, expected_output, atol=1e-5)}")

assert torch.allclose(output_tensor, expected_output, atol=1e-5), f"Rank {rank} output mismatch"

print(f"Rank {rank}: 2D all-to-all-v test PASSED!")

# Test with major alignment
print(f"\nRank {rank}: Testing with major alignment...")

# Create new output tensor for aligned test
aligned_output_tensor = symm_mem.empty(output_size + 16, dtype=torch.float32, device=f"cuda:{rank}")  # Extra space for alignment

# Use major alignment of 16
major_align = 16
torch.ops.symm_mem.all_to_all_vdev_2d(input_tensor, aligned_output_tensor, in_splits, out_splits_offsets, group_name, major_align)

print(f"Rank {rank}: Aligned output tensor = {aligned_output_tensor}")
print(f"Rank {rank}: 2D all-to-all-v with alignment test completed!")

print(f"\nAll tests completed successfully!")
print(f"Usage: torchrun --standalone --nnodes=1 --nproc-per-node=2 {__file__}")
# torchrun --standalone --nnodes=1 --nproc-per-node=2 test_a2a_vdev_2d.py