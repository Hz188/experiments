# %%
class Dog(object):
    
    def __init__(self) -> None:
        pass
        
    def eat(self):
        print("Dog eat.")

class Cat(object):
    
    def __init__(self) -> None:
        pass

    def eat(self):
        print("Cat eat.")

def eat(animal):
    animal.eat()
    
eat(animal=Dog())
eat(animal=Cat())
# %%
