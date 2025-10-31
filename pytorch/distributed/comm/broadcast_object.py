import tempfile
from contextlib import nullcontext

import torch
import torch.distributed as dist
import os
import torch.multiprocessing as mp

def comm(rank, world_size):
    os.environ['MASTER_ADDR'] = 'localhost'
    os.environ['MASTER_PORT'] = '12355'
    # 初始化进程组
    dist.init_process_group("nccl", rank=rank, world_size=world_size)
    torch.cuda.set_device(rank)

    context = tempfile.TemporaryDirectory() if dist.get_rank() == 0 else nullcontext()
    torch.cuda.set_device(dist.get_rank())
    # with context:
    with context as f: 
        if dist.get_rank() == 0:
            broadcast_objects = [f] # any picklable object
            print(f)
        else:
            broadcast_objects = [None]
        dist.broadcast_object_list(broadcast_objects, src=0)
        print(broadcast_objects)
         



if __name__ == "__main__":
    world_size = 2  # 假设有2个进程
    mp.spawn(comm, args=(world_size,), nprocs=world_size, join=True)