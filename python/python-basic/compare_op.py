# %%
x = 1
y = 1
z = 2

# %%
x == y, x == z

# %%
x < y, x < z

# %%
x > y

# %%

z <= x <= y

# %%

x != y

# %%
x is y

# %%
x = 1000
y = 1000
x is y

# %%
x is not y

# %%
x = 1000
y = [1000, 2000]
x in y, x not in y

# %%
x = y = [1, 2, 3]
z = [1,2,3]
x == y, x is y,x == z,  x is z

# %%
# 实际上，字符是根据顺序值排列的。要获悉字母的顺序值，可使用函数ord。这个函数的作用与函数chr相反
idx = ord('a')
idx

# %%
char = chr(idx)
char

# %%



