
import paddle
import os
import paddle.distributed as dist

dist.init_parallel_env()
print(f"Rank: {os.getenv('PADDLE_TRAINER_ID')}, World Size: {os.getenv('PADDLE_TRAINERS_NUM')}")
if dist.get_rank() == 0:
    data = paddle.to_tensor([7, 8, 9])
    print("000")
    dist.recv(data, src=1)
else:
    print("111")
    data = paddle.to_tensor([1, 2, 3])
    dist.send(data, dst=0)
print(data)