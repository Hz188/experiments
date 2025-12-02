import torch
import torch.distributed as dist
import torch.distributed._symmetric_memory as symm_mem


    
dist.init_process_group("nccl")

rank = dist.get_rank()
world_size = dist.get_world_size()
torch.cuda.set_device(f"cuda:{rank}")

# Setup symmetric memory backend
symm_mem.set_backend("NVSHMEM")
group_name = dist.group.WORLD.group_name
symm_mem.enable_symm_mem_for_group(group_name)
        
# Test parameters
elements_per_rank = 2
total_elements = elements_per_rank * world_size

# Create input tensor with rank-specific data
input_tensor = symm_mem.empty(total_elements, dtype=torch.float32, device=f"cuda:{rank}")
input_tensor.fill_(float(rank))

# Create output tensor
output_tensor = symm_mem.empty(total_elements, dtype=torch.float32, device=f"cuda:{rank}")

# Rendezvous both input and output tensors
# symm_mem.rendezvous(input_tensor, group=group_name)
# symm_mem.rendezvous(output_tensor, group=group_name)

# Setup splits - each rank sends equal amount to all peers
in_splits = symm_mem.empty(world_size, dtype=torch.int64,  device=f"cuda:{rank}")
in_splits.fill_(elements_per_rank)

# Rendezvous splits tensor
# symm_mem.rendezvous(in_splits, group=group_name)

# Setup output splits and offsets
out_splits_offsets = symm_mem.empty((2, world_size), dtype=torch.int64, device=f"cuda:{rank}")
out_splits_offsets[0].fill_(elements_per_rank)  # splits
out_splits_offsets[1] = torch.arange(0, elements_per_rank * world_size, 
                                    elements_per_rank, 
                                    dtype=torch.int64, device=f"cuda:{rank}")  # offsets

# Rendezvous splits and offsets tensors
# symm_mem.rendezvous(out_splits_offsets, group=group_name)

# Perform all-to-all-v operation
print(f"{rank=}, {input_tensor=}")
torch.ops.symm_mem.all_to_all_vdev( input_tensor, output_tensor, in_splits, out_splits_offsets, group_name)
print(f"{rank=}, {output_tensor=}")

# Verify results
expected_output = torch.cat([
    torch.full((elements_per_rank,), float(i), dtype=torch.float32, 
                device=f"cuda:{rank}") for i in range(world_size)
])

torch.cuda.synchronize()
assert torch.allclose(output_tensor, expected_output, atol=1e-5)

# torchrun  --standalone --nnodes=1 --nproc-per-node=2 test_a2a_vdev.py