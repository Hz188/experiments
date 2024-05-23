# %%
import torch
import torch.nn.functional as F
t4d = torch.empty(3, 3, 4, 2)
p1d = (1, 1) # pad last dim by 1 on each side
out = F.pad(t4d, p1d, "constant", 0)  # effectively zero padding
print(out.size())
p2d = (1, 1, 2, 2) # pad last dim by (1, 1) and 2nd to last by (2, 2)
out = F.pad(t4d, p2d, "constant", 0)
print(out.size())
t4d = torch.empty(3, 3, 4, 2)
p3d = (0, 1, 2, 1, 3, 3) # pad by (0, 1), (2, 1), and (3, 3)
out = F.pad(t4d, p3d, "constant", 0)
print(out.size())

'''
p3d = (0, 1, 2, 1, 3, 3) # pad by (0, 1), (2, 1), and (3, 3)
means
- last dim left pad 0, right pad 1
- 2nd to last dim left pad 2, right pad 1
- 3nd to last dim left pad 3, right pad 3
so
- 3,3,4,2 -> 3, 3+3+3, 2+4+1, 0+2+1 = 3,9,7,3
'''
# %%
