'''
模型类型转型用例

class A
-> a = A()

class B

b = B.from(a)

'''
# %%

class A:
    
    def __init__(self):
        self.a = {
            1:"a",
            2:"b"
        }
        
class B:
    
    def __init__(self):
        pass

    def set_up(self):
        # self.b = 2
        # self
        print(self)
        print(self.a)
        # print(self.b)

    @staticmethod
    def from_native_module(a):
        a.__class__ = B
        a.set_up()
        
b = B()
a = A()

print(a.a)
B.from_native_module(a)

# %%
