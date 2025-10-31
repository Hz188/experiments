# %%
class Fibs:
    def __init__(self):
        self.a = 0
        self.b = 1
    def __next__(self):
        self.a, self.b = self.b, self.a + self.b
        return self.a
    def __iter__(self):
        return self

'''
__iter__返回一个迭代器  这个迭代器有__next__方法 
调用__next__方法时候应该返回其下一个值
如果没有值可返回 则引发StopIteration异常

next(it) 和 it.__next__()在简单的情况下都等效
'''

fibs = Fibs()
for f in fibs:
    print(f)
    if f > 100:
        break
# %%
fibs = Fibs()
it = iter(fibs)
next(it), next(it), next(it)
# %%
'''
使用迭代器创建序列
'''
class TestIterator:
    value = 0
    def __next__(self):
        self.value += 1
        if self.value > 10: raise StopIteration
        return self.value
    def __iter__(self):
        return self

ti = TestIterator()
list(ti)
# %%
