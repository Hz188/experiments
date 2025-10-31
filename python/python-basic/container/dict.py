# %%
phonebook = {'Alice': '2341', 'Beth': '9102', 'Cecil': '3258'}
phonebook

# %%
items = [('name', 'Gumby'), ('age', 42)]
d = dict(items)
d, d['name']

# %%
d = dict(name='Gumby', age=42)
d

# %%
len(d), d['age'], 'age' in d

# %%
d['age'] = 33
d

# %%
del d['age']
d

# %%
'name' in d

# %% [markdown]
# # 字典方法

# %%
d = {}
d['name'] = 'Gumma'
d['age'] = 42
d

# %%
return_value = d.clear()
return_value, d

# %%
x = {}
y = x
x['key'] = 'value'
x = {}
x, y

# %%
x = {}
y = x
x['key'] = 'value'
y

# %%
x.clear()
y

# %%
x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz']}
y = x.copy()
y['username'] = 'mlh'
y['machines'].remove('bar')
y,x

# %%
import copy
x = {'username': 'admin', 'machines': ['foo', 'bar', 'baz']}
y = copy.deepcopy(x)
y['username'] = 'mlh'
y['machines'].remove('bar')
y,x

# %%
{}.fromkeys(['name', 'age'])

# %%
dict.fromkeys(['name', 'age'])

# %%
dict.fromkeys(['name', 'age'], '(unknown)')

# %%
# d['k'] 会报错，如果k不存在
d.get('k', 555)

# %%
d

# %%
d = {'title': 'Python Web Site', 'url': 'http://www.python.org', 'spam': 0}
d.items()

# %%
d.keys(), d.values()

# %%
d = {'x': 1, 'y': 2}
d.pop('x')
d

# %%
d = {'url': 'http://www.python.org', 'spam': 0, 'title': 'Python Web Site'}
d.popitem()
d

# %%
d = {}
d.setdefault("name", "N/A"), d

# %%
d['name'] = 'Gumby'
d.setdefault('name', 'N/A'), d

# %%
d = {
 'title': 'Python Web Site',
 'url': 'http://www.python.org',
 'changed': 'Mar 14 22:09:15 MET 2016'
}
x = {'title': 'Python Language Website'}
d.update(x)
d

# %%



