# %%
def add(a=1, b=2):  # 使用名称指定的参数称为关键字参数
    return a + b
add(3,4)

# %%
add(3)
# %%
add(b=2)
# %%
def sub(a, b=1):  # a这种叫做位置参数
    return a-b

sub(b=2) # TypeError: sub() missing 1 required positional argument: 'a'

# %%
sub(1), sub(1, 2), sub(1,b=3)
# %%
