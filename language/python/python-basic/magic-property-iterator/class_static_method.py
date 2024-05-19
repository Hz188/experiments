# %%
class A:
    
    def static_method(self):
        print("static method call.")
    static_method = staticmethod(static_method)

    def class_method(cls):
        print("static method call.")
    class_method = classmethod(class_method)
    
# %%
# 或者
class B:

    @staticmethod    
    def static_method(self):
        print("static method call.")

    @classmethod
    def class_method(cls):
        print("static method call.")