# %%
class Class:
    
    def method(self):
        print("I have self args")

instance = Class()
instance.method()
# %%
def function():
    print("I don't have self args.")
    
instance.method =  function
instance.method()
# %%
'''
class语句中定义的代码都在类的命名空间内执行，类的所有成员都可以访问这个命名空间
    类定义本身其实就是要执行的代码段，比如下面这个例子，定义本身就是一个要执行的代码段
'''
class C:
    print("Class C being defined.")

# %%
'''
类作用域中定义了一个变量，所有成员都可以访问，用来计算类的实例的个数
'''
class MemberCounter:
    members = 0
    def __init__(self):
        MemberCounter.members += 1

m1 = MemberCounter()
print(MemberCounter.members)
m2 = MemberCounter()
print(MemberCounter.members)
# %%
'''instance var shadow class var'''
print(m1.members)
m1.members = 'instance var'
print(m1.members)
print(MemberCounter.members)

# %%
