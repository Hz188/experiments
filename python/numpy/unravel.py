# %%
import numpy as np
shape = np.array([2,2,2])
for i in range(8):
    print(np.unravel_index(i, shape))
# %%
np.ravel_multi_index((2,1,3), (4,4,4))

# %%
np.random.randint(0,100,(2,7))

# %%
