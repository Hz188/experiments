# %%
import torch

t_list = [torch.ones(1) + i for i in range(4)]
t_list.append(1)
torch.save(t_list, 't1.pt')
# %%

t_list_2 = torch.load('t1.pt')
t_list_2
# %%
