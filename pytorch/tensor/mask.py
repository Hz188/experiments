# %%
import torch
import torch.nn as nn

# %%
mask = torch.tril(torch.ones(5, 5))
mask

# %%
inp = torch.arange(25).reshape(5,5).float()
inp
# %%
inp.masked_fill(mask == 0, float('-inf'))
# %%
