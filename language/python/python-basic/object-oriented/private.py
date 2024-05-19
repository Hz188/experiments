# %%
class Private:
    
    def __private_method(self):
        print("private method call.")
    
    def public_method(self):
        self.__private_method()
        
p = Private()
p.public_method()
# %%
p.__private_method()
# AttributeError: 'Private' object has no attribute '__private_method'
# %%
# Essentially, it's a name change.
p._Private__private_method()
# %%
