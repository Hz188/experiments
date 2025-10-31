# %%
str1 = "aaa"
str2 = "bbb"
def func():
    str1 = "ccc"
    print(str1+str2)

func()
# %%
# 使用 globals()
def func2(param):
    str1 = "ccc"
    print(param + globals()["str1"])
func2("ddd")
# %%
# 使用 global 在局部作用域内重新关联全局变量
x = 1
def func3():
    global x
    x = x + 1
    print(x)
    
func3()
# %%
