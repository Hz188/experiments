from torch.nn import Module
from torch import nn
import torch

class Net(Module):
    def __init__(self):
        super(Net, self).__init__()
        self.layer1 = nn.Linear(1, 1, bias=False)
        self.layer2 = nn.Linear(1, 1, bias=False)
        self.layer1.weight.data.zero_()
        self.layer1.weight.data += 1
        self.layer2.weight.data.zero_()
        self.layer2.weight.data += 1
    
    def forward(self, x, rank=0):
        layer = f'layer{1 if rank % 2 == 1 else 2}'
        return getattr(self, layer)(x)

import torch.distributed as dist
dist.init_process_group('gloo')

rank = int(dist.get_rank())

# find_unused_parameters = False
find_unused_parameters = True
net = nn.parallel.DistributedDataParallel(Net(), find_unused_parameters=find_unused_parameters)

input = torch.zeros(rank + 1, 1).to(torch.float32) + 1

output = net(input, rank=rank)
target = torch.zeros_like(input)
loss = (0.5 * (output - target) ** 2).sum()
loss.backward()

print(f'rank {rank}, layer 1, grad {net.module.layer1.weight.grad}')
print(f'rank {rank}, layer 2, grad {net.module.layer2.weight.grad}')
