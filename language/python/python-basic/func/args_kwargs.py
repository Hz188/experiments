# %%
def func(*args, **kwagrs):
    print(f"args: {args}")
    print(f"*args: {args}")
    print(f"kwargs: {kwagrs}")
func(1,2,3, a=1,b=2)
