import os

import torch
import torch.distributed as dist
import torch.distributed._symmetric_memory as symm_mem
dist.init_process_group("nccl")

rank = dist.get_rank()

torch.cuda.set_device(f"cuda:{rank}")

# symm_mem.set_backend("NVSHMEM")
# symm_mem.set_backend("NCCL")
symm_mem.set_backend("CUDA")
# print(symm_mem.get_backend(torch.device(f"cuda:{rank}")))
t = torch.tensor([1.0], device=f"cuda:{rank}")  # 明确指定设备


group_name = dist.group.WORLD.group_name
symm_mem.enable_symm_mem_for_group(group_name)
# Allocate a tensor
dtype = torch.float
numel = 128
device = torch.cuda.current_device()
out = symm_mem.empty(numel, dtype=dtype, device=torch.device(f"cuda:{device}"))
hdl = symm_mem.rendezvous(out, group=group_name)

# torch.ops.symm_mem.multimem_all_reduce_(out, "sum", group_name)  # pdc H卡可以跑 node65报错
#  torchrun  --standalone --nnodes=1 --nproc-per-node=2 hello_world.py   # pdc H卡可以跑 