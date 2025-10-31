# %%
process_exception = True
process_exception = False
try:
    x = 1
    y = 0
    z = x / y
except ZeroDivisionError:
    if process_exception:   
        print("divided by 0.")
    else:
        raise
# %%
'''
进入except子句的异常将被作为异常上下文存储起来，并出现在最终的错误消息中
'''
try:
    1 / 0
except ZeroDivisionError:
    raise ValueError
# %%
try:
    1/0
except ZeroDivisionError:
    raise ValueError from None
# %%
try:
    x = 1
    y = 0
    # print(x / y)
    z = [1,2,3]
    z[4]
except ZeroDivisionError:
    print("The second number can't be zero!")
except IndexError:
    print("Index out of bound.")
# %%
try:
    x = 1
    y = 0
    z = [1,2,3]
    print(x / y)
    z[4]
except (ZeroDivisionError, IndexError) as e:
    print(e)
else:
    print("else")
finally:
    print("finally")
# %%
