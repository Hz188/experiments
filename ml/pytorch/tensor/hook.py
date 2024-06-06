# %%
import torch
v = torch.tensor([0., 0., 0.], requires_grad=True)
lr = 0.01
# simulate a simple SGD update
# h = v.register_post_accumulate_grad_hook(lambda p: p.add_(p.grad, alpha=-lr))
h = v.register_post_accumulate_grad_hook(lambda p: print(p))
v.backward(torch.tensor([1., 2., 3.]))
h.remove()  # removes the hook

# %%

h = v.register_hook(lambda p: print(p))
v.backward(torch.tensor([1., 2., 3.]))
v
h.remove()


'''
两种hook表现一致，输入不同
    一个输入是grad
    一个输入是param
'''
# %%
