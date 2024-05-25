# %%
import torch

def print_tensor_info(t: torch.Tensor):
    print("==============================")
    print(f"{t.storage()}")
    print(f"tensor dtype = {t.dtype}")
    print(f"tensor elem size = {t.storage().element_size()}")
    print(f"tensor nbytes = {t.storage().nbytes()}")
    print(f"number of elem in this tensor = {t.storage().size()}")
    print("==============================")

numel = 3
t = torch.tensor(range(numel))
print_tensor_info(t)
t.storage().resize_(0)
print_tensor_info(t)
t.storage().resize_(numel)
print_tensor_info(t)
# %%
