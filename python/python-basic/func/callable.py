# %%
from typing import Callable
def add(x: int, y: int) -> int:
    return x + y

# %%
add is Callable, callable(add)
# %%
