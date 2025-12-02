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

# Test parameters for asymmetric communication
initial_elements_per_rank = 4  # Each rank starts with 4 elements
send_pattern = [3, 1]  # Each rank sends 3 elements to rank 0, 1 element to rank 1

# Calculate output sizes for each rank
output_size_rank0 = send_pattern[0] * world_size  # rank 0 receives 3 from each rank
output_size_rank1 = send_pattern[1] * world_size  # rank 1 receives 1 from each rank

# Create input tensor with rank-specific data
input_tensor = symm_mem.empty(initial_elements_per_rank, dtype=torch.float32, device=f"cuda:{rank}")
input_tensor.fill_(float(rank))

# Create output tensor with appropriate size for this rank
if rank == 0:
    output_size = output_size_rank0
else:
    output_size = output_size_rank1

output_tensor = symm_mem.empty(output_size, dtype=torch.float32, device=f"cuda:{rank}")


# Setup input splits - how much each rank sends to each peer
in_splits = symm_mem.empty(world_size, dtype=torch.int64, device=f"cuda:{rank}")
in_splits.copy_(torch.tensor(send_pattern, dtype=torch.int64, device=f"cuda:{rank}"))


# Setup output splits and offsets
out_splits_offsets = symm_mem.empty((2, world_size), dtype=torch.int64, device=f"cuda:{rank}")

# Calculate how much each rank receives from each peer
if rank == 0:
    # rank 0 receives 3 elements from each rank
    out_splits_offsets[0].fill_(send_pattern[0])
    # Calculate offsets for rank 0's output
    offsets = torch.arange(0, send_pattern[0] * world_size, send_pattern[0], 
                          dtype=torch.int64, device=f"cuda:{rank}")
else:
    # rank 1 receives 1 element from each rank
    out_splits_offsets[0].fill_(send_pattern[1])
    # Calculate offsets for rank 1's output
    offsets = torch.arange(0, send_pattern[1] * world_size, send_pattern[1], 
                          dtype=torch.int64, device=f"cuda:{rank}")

out_splits_offsets[1].copy_(offsets)


# Print initial state
print(f"Rank {rank}:")
print(f"  Input tensor: {input_tensor}")
print(f"  Output tensor size: {output_tensor.shape}")
print(f"  Send pattern (to each rank): {in_splits}")
print(f"  Receive pattern (from each rank): {out_splits_offsets[0]}")
print(f"  Offsets: {out_splits_offsets[1]}")

# Perform all-to-all-v operation
torch.ops.symm_mem.all_to_all_vdev(input_tensor, output_tensor, in_splits, out_splits_offsets, group_name)

# Print results
print(f"  Output tensor after all-to-all: {output_tensor}")

# Verify results
torch.cuda.synchronize()

if rank == 0:
    # rank 0 should receive 3 elements from each rank
    expected_output = []
    for i in range(world_size):
        expected_output.extend([float(i)] * send_pattern[0])
    expected_output = torch.tensor(expected_output, dtype=torch.float32, device=f"cuda:{rank}")
    
    print(f"  Expected output: {expected_output}")
    assert torch.allclose(output_tensor, expected_output, atol=1e-5), f"Rank 0 output mismatch"
    print(f"  Rank 0 verification PASSED: received {output_size_rank0} elements")

else:
    # rank 1 should receive 1 element from each rank
    expected_output = torch.tensor([float(i) for i in range(world_size)], 
                                  dtype=torch.float32, device=f"cuda:{rank}")
    
    print(f"  Expected output: {expected_output}")
    assert torch.allclose(output_tensor, expected_output, atol=1e-5), f"Rank 1 output mismatch"
    print(f"  Rank 1 verification PASSED: received {output_size_rank1} elements")

print(f"Rank {rank} asymmetric all-to-all test completed successfully!")

# Usage: torchrun --standalone --nnodes=1 --nproc-per-node=2 test_a2a_vdev_uneven.py