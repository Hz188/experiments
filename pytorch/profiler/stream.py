# Stream test

import os

import torch
import torch.distributed as dist
from torch.profiler import profile, ProfilerActivity, schedule, tensorboard_trace_handler

import colossalai
rank = int(os.environ['RANK'])
world_size = int(os.environ['WORLD_SIZE'])
# dist.init_process_group(backend='nccl')

colossalai.launch_from_torch({})

torch.cuda.set_device(rank)

device = torch.device('cuda', rank)

prof = profile(
    activities=[
        ProfilerActivity.CPU,
        ProfilerActivity.CUDA,
    ],
    schedule=schedule(wait=0, warmup=1, active=1),
    on_trace_ready=tensorboard_trace_handler('./log'),
    with_stack=True
)

size = 10000
shape = (size, size)
dist.Work
a = torch.randn(shape, device=device)
b = torch.randn(shape, device=device)

cpu_t = torch.randn(shape, device='cpu', pin_memory=True)
gpu_t = torch.empty_like(cpu_t, device=device)
s = torch.cuda.Stream(device)
# s = None
with prof:
    for _ in range(2):
        ops = []
        for _ in range(5):
            with torch.cuda.stream(s):
                gpu_t = cpu_t.to(device, non_blocking=False)
                res = [torch.empty_like(gpu_t) for _ in range(world_size)]
                ops.append(dist.all_gather(res, gpu_t, async_op=True))
            for _ in range(2):
                c = a @ b
        for op in ops:
            op.wait()
        prof.step()
