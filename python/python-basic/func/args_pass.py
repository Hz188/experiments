# %%
def change_val(a):
    a = 5
b = 10
change_val(b)
b

# %%
def change_list_elem(a):
    a[0] = 5

b = [10,11,12]
change_list_elem(b)
b

# %%
b = [10,11,12]
c = b[:]
c == b, c is b

# %%
def f(a,b,c,*,d):
    print(a,b,c,d)

# f(1,2,3,4)  # fail
f(1,2,3,d=4)  # pass
# %%
