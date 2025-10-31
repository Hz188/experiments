import paddle

x = paddle.to_tensor(1)
print(x.item())             #1
print(type(x.item()))       #<class 'int'>

x = paddle.to_tensor(1.0)
print(x.item())             #1.0
print(type(x.item()))       #<class 'float'>

x = paddle.to_tensor(True)
print(x.item())             #True
print(type(x.item()))       #<class 'bool'>

x = paddle.to_tensor(1+1j)
print(x.item())             #(1+1j)
print(type(x.item()))       #<class 'complex'>

x = paddle.to_tensor([[1.1, 2.2, 3.3]])
print(x.item(2))            #3.3
print(x.item(0, 2))         #3.3
