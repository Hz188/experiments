# %%
import torch
import torch.nn as nn

class MLP(nn.Module):
    
    def __init__(self):
        super(MLP, self).__init__()
        self.param = nn.Parameter(torch.tensor([1.0,2.0,3.0]))
        self.fc1 = nn.Linear(5, 10)
        self.fc2 = nn.Linear(10, 20)

model = MLP()
# %%
# paramters只会打印nn.Parameter，如果recurse=False，就只会打印当前模型的init中的nn.Parameter，不会打印子module的
for p1, p2 in zip(model.parameters(), model.named_parameters()):
    print(f'{p1.shape}\n{p2[0]}\t{p2[1].shape}')
print("-"*50)
for p1, p2 in zip(model.parameters(recurse=False), model.named_parameters(recurse=False)):
    print(f'{p1.shape}\n{p2[0]}\t{p2[1].shape}')
# %%
for m in model.modules():
    print(m)
# %%
for idx, m in enumerate(model.named_modules()):
    print(f"{idx}-->{m}")
# %%
