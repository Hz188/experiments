# %%
words = ['this', 'is', 'an', 'ex', 'parrot']
for word in words:
    print(word)

# %%
nums = [1,2,3,4,5]
for num in nums:
    print(num)

# %%
for i in range(10):
    print(i)

# %%
d = {'x': 1, 'y': 2, 'z': 3}
for key in d:
    print(key, 'corresponds to', d[key])

# %%
print(list(d.keys()))
for k in d.keys():
    print(k, 'corresponds to', d[k])

# %%
for v in d.values():
    print(v)

# %%
for k, v in d.items():
    print(f"{k} --> {v}")

# %%
names = ['anne', 'beth', 'george', 'damon']
ages = [12, 45, 32, 102]
for i in range(len(names)):
    print(names[i], 'is', ages[i], 'years old')

# %%
# zip 缝合
# 序列的长度不同时，函数zip将在最短的序列用完后停止“缝合
print(list(zip(names, ages)))
for name, age in zip(names, ages):
    print(f"{name} --> {age}")

# %%
strings = ["aaaa", "bbbb", "xxx"]
for index, string in enumerate(strings):
    if 'xxx' in string:
        strings[index] = '[censored]'
strings

# %%
sorted([4, 3, 6, 8, 3])

# %%
sorted('Hello, world!')

# %%
reversed("Hello, world!"), list(reversed('Hello, world!'))

# %%
''.join(reversed('Hello, world!'))

# %%
[x*x for x in range(5)]

# %%
[(x, y) for x in range(3) for y in range(3)]

# %%
[(x, y) for x in range(3) for y in range(3) if x == y]

# %%



