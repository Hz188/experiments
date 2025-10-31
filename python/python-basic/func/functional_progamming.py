# %%
# map(func, seq[, seq, ...]) 对序列中的所有元素执行函数
l = map(lambda x: 2*x, range(10))
list(l)
# %%
# 等价于
[x*2 for x in range(10)]
# %%
# filter(func, seq) 返回一个列表，其中包含对其执行函数时结果为真的所有元素
l = filter(lambda x: x.isdigit(), ['1', '2', 'a'])
list(l)
# %%
[x for x in ['1', '2', 'a'] if x.isdigit()]
# %%
from functools import reduce
# reduce(func, seq[, initial]) 等价于 func(func(func(seq[0], seq[1]), seq[2]), ...)
l = reduce(lambda x,y: x+y, range(5))
l
# %%
# sum(seq) 返回 seq 中所有元素的和
sum([1,2,3])