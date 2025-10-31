# %%
import torch
v = torch.tensor([0., 0., 0.], requires_grad=True)
lr = 0.01
# simulate a simple SGD update
# h = v.register_post_accumulate_grad_hook(lambda p: p.add_(p.grad, alpha=-lr))
h = v.register_post_accumulate_grad_hook(lambda p: print(p))  # 输入是param
v.backward(torch.tensor([1., 2., 3.]))
h.remove()  # removes the hook

# %%

h = v.register_hook(lambda p: print(p))  # 输入是grad
v.backward(torch.tensor([1., 2., 3.]))
v
h.remove()

# %%
'''
两种hook表现一致，输入不同
    一个输入是grad
    一个输入是param
    
同时register_post_accumulate_grad_hook只能应用在叶子节点上
'''

# %%
# register_hook的作用过程大致如：p.grad = hook_function(p.grad)
# 看下面两个验证例子
def hook_function(grad):
    grad*2
v = torch.tensor([0., 0., 0.], requires_grad=True)

h = v.register_hook(hook=hook_function)  # double the gradient
v.backward(torch.tensor([1., 2., 3.]))
v.grad

# %%
def hook_function(grad):
    return grad*2
v = torch.tensor([0., 0., 0.], requires_grad=True)

h = v.register_hook(hook=hook_function)  # double the gradient
v.backward(torch.tensor([1., 2., 3.]))
v.grad
# %%
