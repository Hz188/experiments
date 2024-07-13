import torch
import torch.distributed as dist
import os
import torch.multiprocessing as mp

def run_all_to_all_single(rank, world_size):
    os.environ['MASTER_ADDR'] = 'localhost'
    os.environ['MASTER_PORT'] = '12355'
    # 初始化进程组
    dist.init_process_group("nccl", rank=rank, world_size=world_size)
    torch.cuda.set_device(rank)

    # 每个进程创建一个张量，将其数值设置为其rank值
    if rank == 0:
        tensor = torch.ones(6, 1).cuda() * rank
    if rank == 1:
        tensor = torch.ones(0, 1).cuda() * rank


    # 为接收张量分配空间

    # 打印发送前的tensor
    print(f'Rank {rank} before all_to_all_single: {tensor}')

    # 执行 all-to-all 单张量通信
    input_splits = [[6, 0], [0, 0]]
    output_splits = [[6, 0], [0, 0]]
    recv_tensor = torch.empty(sum(output_splits[rank])).cuda()
    dist.all_to_all_single(recv_tensor, tensor, output_splits[rank], input_splits[rank])

    # 打印接收到的tensor
    print(f'Rank {rank} after all_to_all_single: {recv_tensor}')

    # 清理进程组
    dist.destroy_process_group()

if __name__ == "__main__":
    world_size = 2  # 假设有2个进程
    mp.spawn(run_all_to_all_single, args=(world_size,), nprocs=world_size, join=True)
