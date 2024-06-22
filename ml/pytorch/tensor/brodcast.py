# %%
import torch
input = torch.arange(24).reshape(2, 3, 4) 
weight = torch.tensor([[1,1,1], [2,2,2]])
input, weight
# %%
a = input * weight[:,:,None]
a
# %%

a.sum(dim=-2)
# %%
