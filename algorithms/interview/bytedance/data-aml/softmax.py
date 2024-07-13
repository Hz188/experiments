import torch
import torch.nn as nn

class SoftmaxLossLayer(nn.Module):
    
    def __init__(self):
        pass

    def forward(self, inp):
        # inp: (b, c)
        inp_max = torch.max(inp, dim=-1, keepdim=True) # (b, 1)
        inp_exp = torch.exp(inp-inp_max)  # (b, c)
        inp_exp_sum = torch.sum(
            inp_exp, dim=-1, keepdim=True
        )
        self.prob = inp_exp / inp_exp_sum
        return self.prob

    def get_loss(self, label):
        self.batch_size = self.prob.shape[0]
        self.label_onehot = torch.zeros_like(self.prob)
        self.label_onehot[torch.arange(self.batch_size), label] = 1.0
        loss = -torch.sum(
            torch.log(self.prob) * self.label_onehot
        ) / self.batch_size
        return loss
        
    def backward(self):
        bottom_diff = (self.prob - self.label_one_hot) / self.batch_size
        return bottom_diff