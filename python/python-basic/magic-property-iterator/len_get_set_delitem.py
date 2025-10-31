# %%
class A:
    
    def __init__(self, size=10) -> None:
        self.elem = list(range(10))
    def __len__(self):
        return len(self.elem)
    def __getitem__(self, i):
        return self.elem[i]
    def __setitem__(self, i, v):
        self.elem[i] = v

a = A(10)
a.elem
# %%
print(a[0])
a[0] = 10
print(a[0])
# %%
# 简单的需求可以通过直接继承 list dict str实现
class MyList(list):
    
    def __init__(self, *args):
        super().__init__(*args)
        self.get_count = 0
    def __getitem__(self, i):
        self.get_count += 1
        return super().__getitem__(i)

l = MyList(range(10))
print(l)
l[0], l[1], f"l.get_count: {l.get_count}"
# %%
