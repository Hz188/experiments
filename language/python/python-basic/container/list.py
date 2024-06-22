# %%
list("hello")

# %%
"".join(['a','b','c'])

# %%
x = [1,2,3]
x[0]=-1
x

# %%
del x[0]
x

# %%

name = list("Tom")
name[1:] = list("im")
name

# %%
# insert
x = [1,5]
x[1:1] = [2,3,4]
x

# %%
# delete
x[1:4] = []
x

# %%
x = [1,2,3,4,5]
x.append(6)
x

# %%
x = [1,2,3,4,5]
x.clear()
x

# %%
# copy
x = [1,2,3,4,5]
y = x
y[0] = 0
x, y

# %%
x = [1,2,3,4,5]
y = x.copy()
y[0] = 0
x, y

# %%
s = ['to', 'be', 'or', 'not', 'to', 'be']
s.count('to')

# %%
x = [[1, 2], 1, 1, [2, 1, [1, 2]]]
x.count(1), x.count([1,2])

# %%
a = [1,2,3]
b = [4,5,6]
a.extend(b)
b[0] = 8
a, b

# %%
a = [1, 2, 3]
b = [4, 5, 6]
a + b # a不变 a = a + b效率低
a, b

# %%
a = [1, 2, 3]
b = [4, 5, 6]
a[len(a):] = b
a, b

# %%
knights = ['We', 'are', 'the', 'knights', 'who', 'say', 'ni']
knights.index('say')

# %%
numbers = [1, 2, 3, 5, 6, 7]
numbers.insert(3, 'four')
numbers

# %%
x = [1,2,3]
x[1:1] = [4]
x

# %%
x = [1, 2, 3]
x.pop()
x

# %%
x = [1,2,3]
x.pop(0)
x

# %%
x = ['to', 'be', 'or', 'not', 'to', 'be']
x.remove('be')
x

# %%
x = [1,2,3]
x.reverse()
x

# %%
x = [4, 6, 2, 1, 7, 9]
x.sort() # sort no return value
x

# %%
x = [4,5,6,1,2,3]
y = x.copy()
y.sort()
x, y

# %%
x = [4,5,6,1,2,3]
y = sorted(x)
x, y

# %%
sorted('Python') # sorted suit any iterable object

# %%
x = ['aardvark', 'abalone', 'acme', 'add', 'aerate']
x.sort(key=len)
x

# %%
x = [4, 6, 2, 1, 7, 9]
x.sort(reverse=True)
x

# %%

a = [1, 2, 3]
b = [4, 5, 6]
a.extend(b)
a, b
