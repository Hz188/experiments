import os

import torch
import torch.distributed as dist
import torch.distributed._symmetric_memory as symm_mem
dist.init_process_group("nccl")

rank = dist.get_rank()

torch.cuda.set_device(rank)

# symm_mem.set_backend("NVSHMEM")
symm_mem.set_backend("NCCL")
# symm_mem.set_backend("CUDA")

# print(symm_mem.get_backend(torch.device(f"cuda:{rank}")))

group_name = dist.group.WORLD.group_name
symm_mem.enable_symm_mem_for_group(group_name)
# Allocate a tensor
dtype = torch.float
numel = 128
device = torch.cuda.current_device()
out = symm_mem.empty(numel, dtype=dtype, device=torch.device(f"cuda:{device}"))
dist.barrier()
symm_mem.rendezvous(out, group=group_name)

#  torchrun  --standalone --nnodes=1 --nproc-per-node=2 hello_world.py 