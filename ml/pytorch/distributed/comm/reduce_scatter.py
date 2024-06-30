# %%
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

    # 每个进程创建一个张量，将其数值设置为其rank值
    input_tensor = torch.ones(4).cuda() + rank
    output_tensor = torch.empty(2).cuda()
    # 为接收张量分配空间

    # 打印发送前的tensor
    print(f'Rank {rank} before reduce_scatter: {output_tensor}')

    # 执行 all-to-all 单张量通信
    dist.reduce_scatter_tensor(output_tensor, input_tensor) 

    # 打印接收到的tensor
    print(f'Rank {rank} after reduce_scatter: {input_tensor}')

    # 清理进程组
    dist.destroy_process_group()

if __name__ == "__main__":
    world_size = 2  # 假设有2个进程
    mp.spawn(comm, args=(world_size,), nprocs=world_size, join=True)