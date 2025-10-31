# %%
nested = [
    [1,2],
    [3,4],
    [5],
]
def flatten(nested):
    for sublist in nested:
        for elem in sublist:
            yield elem
        
'''
包含yield的函数被称为生成器
'''
for num in flatten(nested=nested):
    print(num, end=',')
# %%
list(flatten(nested=nested))
# %%
'''
列表推导[] -> ():生成器推导
    简单情形下，不如使用列表推导,但如果要包装可迭代对象（可能生成大量的值），使用列表推导将立即实例化一个列表，从而丧失迭代的优势
'''
g = (i**2 for i in range(5))
g, list(g)
# %%
'''
另一种优势是，可以在既有的圆括号内使用生成器推导，无需多加括号
'''
sum(i**2 for i in range(5))
# %%
