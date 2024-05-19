# %%
def func(*args, **kwagrs):
    print(f"args: {args}")
    print(f"*args: {args}")
    print(f"kwargs: {kwagrs}")
# %%
# *args这种用法叫做收集参数
def func1(*args):
    print(args)
func1(1)
# %%
func1(1,2,3)
# %%
# 星号意味着收集余下的位置参数
def func2(a, *args):
    print(a)
    print(args)
func2(1,2,3,4)
# %%
# 不提供则是空元祖
func2(1)
# %%
# 收集参数可以放在其他位置，而不是最后，这种用法需要指定后续的参数
def func3(a, *b, c):
    print(a, b, c)
func3(1,2,3,4,c=5)
func3(1,2,3,4,5)  # TypeError: func3() missing 1 required keyword-only argument: 'c'
# %%
# *不会收集关键字参数
def func4(a,  *b):
    print(a, b)
func4(1,2,3,b=4)  # TypeError: func4() got an unexpected keyword argument 'b'
# %%
# 收集关键字参数，需要**
def func5(a, **b):
    print(a, b)
func5(1,b=2,c=3)
# %%
# 结合*和**
def func6(a, *b, **c):
    print(a)
    print(b)
    print(c)
func6(1,2,3, qqq=1,ppp=2,zzz=3)
# %%
# *和**是收集参数到元祖和字典中，同样的，也可以使用相反操作来分配参数
def add(x, y):
    return x + y
param = (1, 2)
param_kw ={'x':1,'y':2}
add(*param), add(**param_kw)
# %%
# 分配参数也可用于参数列表的一部分
def add(x, y, z):
    return x + y + z
param = (1, 2)
param_kw ={'y':1,'z':2}
add(0, *param), add(0, **param_kw)
# %%
# 拆分运算符来传递参数很有用，因为这样无需操心参数个数之类的问题,在调用超类的构造函数时特别有用
def foo(x, y, z, m=0, n=0):
    print(x, y, z, m, n)
def call_foo(*args, **kwds):
    print("Calling foo!")
    foo(*args, **kwds)
call_foo(1,2,3,4)
# %%
