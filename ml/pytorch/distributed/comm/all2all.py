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
    tensor = torch.ones(4, 1).cuda() * rank

    # 为接收张量分配空间

    # 打印发送前的tensor
    print(f'Rank {rank} before all_to_all_single: {tensor}')

    # 执行 all-to-all 单张量通信
    output_size = [[1,1], [3,3]]
    output_shape = [[2,],[6,]]
    recv_tensor = torch.empty(output_shape[rank]).cuda()
    dist.all_to_all_single(recv_tensor, tensor, output_size[rank], [1,3])

    # 打印接收到的tensor
    print(f'Rank {rank} after all_to_all_single: {recv_tensor}')

    # 清理进程组
    dist.destroy_process_group()

if __name__ == "__main__":
    world_size = 2  # 假设有4个进程
    mp.spawn(run_all_to_all_single, args=(world_size,), nprocs=world_size, join=True)

# %%
t = torch.arange(16).reshape(4,4)
t = t.split([2,0,2,0])
# %%
a = [tt + 1 for tt in t]
torch.cat(a)
# %%

a = torch.empty(6, dtype=torch.long)
a[torch.tensor([3,5,0,1,2,4])] = torch.arange(6)
a

# %%

a = torch.randn(2,2,4)
b = torch.tensor([[1,2], [3,4]])
a[0].shape, b[:,0, None].shape
a, (a[0]*b[:,0,None]).shape
# %%
