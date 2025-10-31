# %%
from abc import ABC, abstractmethod
class Animal(ABC):
    
    @abstractmethod
    def eat(self):
        pass
        
class Dog(Animal):
    
    def __init__(self) -> None:
        pass
        
    def eat(self):
        print("Dog eat.")

class Cat(Animal):
    
    def __init__(self) -> None:
        pass

    def eat(self):
        print("Cat eat.")


d = Dog()
isinstance(d, Dog), issubclass(Dog, Animal)
# %%
class Pig:
    
    def eat(self):
        print("Pig eag.")
p = Pig()

def eat(animal: Animal):
    animal.eat()
    
eat(p)
eat(d)
isinstance(p, Animal)
# p可以通过类型检查（因为满足duck-type）但不是Animal的实例
# %%
'''类的注册'''
Animal.register(Pig)
isinstance(p, Animal), issubclass(Pig, Animal)
# %%
