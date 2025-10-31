# %% 
import torch
import torch.nn as nn

t = torch.randn(2, 2)
t
# %%
t.repeat_interleave(2, 0)
# %%
