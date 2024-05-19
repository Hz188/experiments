# %%
def foo():
    def bar():
        print("hello")
    bar()
    
foo()
# %%

def multiply(factor):
    def multiplyByFactor(number):
        return number * factor
    return multiplyByFactor

m1 = multiply(2)
m2 = multiply(3)
m1(1), m2(1)
# %%