# %%
class Filter:
    
    def __init__(self):
        self.blocked = []
    
    def filter(self, seq):
        return [x for x in seq if x not in self.blocked]
    
class OneFilter(Filter):
    
    def __init__(self) -> None:
        super().__init__()

f = OneFilter()
f.blocked = [1]
f.filter([1,2,3,4])
# %%
issubclass(OneFilter, Filter), isinstance(f, Filter), isinstance(f, OneFilter)
# %%
OneFilter.__bases__, Filter.__bases__
# %%
f.__class__
# %%
'''
多个超类，子类会继承每个超类的成员（变量、方法）
    需要注意的是，如果多个超类有相同的方法，那么需要在继承的时候，注意超类的顺序
    前面的类会覆盖后面的类的这个方法
    多个超类的超类相同时，查找特定方法或属性时访问超类的顺序称为方法解析顺序（MRO），它使用的算法非常复杂
'''
class A:
    
    def talk(self):
        print('A')
        
class B:
    
    def talk(self):
        print('B')
        
class C(A, B):
    pass
c = C()
c.talk()
class C(B, A):
    pass
c = C()
c.talk()
# %%
hasattr(A, 'talk'),hasattr(B, 'talk'),hasattr(C, 'talk'), hasattr(c, 'talk')
# %%
callable(getattr(A, 'talk'))
# %%
setattr(c, 'age', 12)
c.age
# %%
c.__dict__
# %%
