# %%
class Rectangle:
    
    def __init__(self) -> None:
        self.width = 0
        self.height = 0
    
    def set_size(self, size):
        self.width, self.height = size
   
    def get_size(self):
        return self.width, self.height 

    size = property(get_size, set_size)

r = Rectangle()
r.width = 5
r.height = 10
r.size
# %%
r.size = 100, 200
r.width, r.height
# %%
# property 和 @property

class C(object):
    def __init__(self):
        self._x = None
 
    def getx(self):
        return self._x
 
    def setx(self, value):
        self._x = value
 
    def delx(self):
        del self._x
 
    x = property(getx, setx, delx, "I'm the 'x' property.")
        
class C(object):
    def __init__(self):
        self._x = None
 
    @property
    def x(self):
        """I'm the 'x' property."""
        return self._x
 
    @x.setter
    def x(self, value):
        self._x = value
 
    @x.deleter
    def x(self):
        del self._x
# %%
