# %%
import torch
from torch._utils import _flatten_dense_tensors, _unflatten_dense_tensors

flat_tensor = torch.arange(4*(2+3+4))
tensor = [torch.ones(4,i) for i in range(2,5)]
# %%
unflat_tensor = _unflatten_dense_tensors(flat_tensor, tensor)
flat_tensor, tensor, unflat_tensor
# %%
