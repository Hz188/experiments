# %%
class DivZero(Exception):
    pass

def div(a, b):
    if b == 0:
        raise DivZero()
    
div(1, 0)
# %%
raise Exception("raise Exception")
# %%
