
from functools import partial
def add(x, y):
    return x + y

    
addone = partial(add, y=1)

if __name__ == "__main__":
    c = add(1, 2)
    z = addone(4)
    print(c)
    print(z)