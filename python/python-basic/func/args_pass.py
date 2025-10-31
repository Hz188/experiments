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
