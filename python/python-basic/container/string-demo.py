# %%
website = 'http://www.python.org'
website[-3:] = 'com'
website # 字符串是不可变的，因此所有的元素赋值和切片赋值都是非法的

# %% [markdown]
# # 格式化字符串

# %%
format = "Hello, %s. %s enough for ya?"
values = ('world', 'Hot')
format % values

# %%
"{}, {} and {}".format("first", "second", "third")

# %%
x = "a"
y = "b"
f"{x}, {y}"

# %%
"{3} {0} {2} {1} {3} {0}".format("be", "not", "or", "to")

# %%
"{foo} {} {bar} {}".format(1, 2, bar=4, foo=3)

# %%
"{foo} {1} {bar} {0}".format(1, 2, bar=4, foo=3)

# %% [markdown]
# # 字符串方法

# %%
import string
string.digits,string.ascii_letters,string.ascii_lowercase,string.printable

# %%
string.punctuation, string.ascii_uppercase

# %%
s = "abc"
s.center(5, "*")

# %%
s.find('b')
# rfind、index、rindex、count、startswith、endswith。

# %%
s.rfind('c'), s.index('a'), s.rindex('a'), s.count('ab'), s.startswith("ab"), s.endswith("bc")

# %%
seq = ['1', '2', '3', '4', '5']
",".join(seq).split(",")


# %%
s = "AbcDEFgh"
s.lower(), s.islower(), s.istitle()

# %%
s.isupper(), s.translate({"A":"1", 'b':2})
# capitalize、casefold、swapcase、title、upper。

# %%
s = "abcdef"
s.replace("abc", "123")

# %%
s = "  abcdef  "
s.strip()
# rstrip, lstrip


# %%
table = str.maketrans('cs', 'kz')
'this is an incredible test'.translate(table)

# %% [markdown]
# # 判断字符串满足条件

# %%
# isalnum、isalpha、isdecimal、isdigit、isidentifier、islower、isnumeric、
# isprintable、isspace、istitle、isupper



