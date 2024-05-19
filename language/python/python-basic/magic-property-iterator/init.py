# %%
class A:
    
    def __init__(self) -> None:
        self.a = 1

class B(A):
    
    def __init__(self) -> None:
        self.b = 2

class C(A):
    
    def __init__(self) -> None:
        super().__init__()
        print(super())
        self.c = 3
b = B()
c = C()
b.__dict__, c.__dict__
# %%
'''
super()
    它返回的是一个super对象，这个对象将负责为你执行方法解析。
    当你访问它的属性时，它将在所有的超类（以及超类的超类，等等）中查找，
    直到找到指定的属性或'引发AttributeError异常。
'''