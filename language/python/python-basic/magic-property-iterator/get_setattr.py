# %%
class Rectangle:
    def __init__ (self):
        self.width = 0
        self.height = 0
    def __setattr__(self, name, value):
        if name == 'size':
            self.width, self.height = value
        else:
            self. __dict__[name] = value
    def __getattr__(self, name):
        if name == 'size':
            return self.width, self.height
        else:
            raise AttributeError()


'''
__getattribute__(self, name)：在属性被访问时自动调用（只适用于新式类）。
__getattr__(self, name)：在属性被访问而对象没有这样的属性时自动调用。
__setattr__(self, name, value)：试图给属性赋值时自动调用。
__delattr__(self, name)：试图删除属性时自动调用。
'''
r = Rectangle()
r.width = 1
r.height = 2
r.width, r.height, r.size
# %%
r.size = 3, 4
r.width, r.height, r.size
# %%
