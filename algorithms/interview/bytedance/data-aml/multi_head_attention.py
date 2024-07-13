from math import sqrt
import torch
import torch.nn as nn
import numpy as np

class SelfAttention(nn.Module):

    dim_in: int
    din_k: int
    dim_v: int
    
    def __init__(self, dim_in, dim_k, dim_v):
        super().__init__()
        self.dim_in = dim_in
        self.dim_k = dim_k
        self.dim_v = dim_v
        self.linear_q = nn.Linear(dim_in, dim_k, bias=False)
        self.linear_k = nn.Linear(dim_in, dim_k, bias=False)
        self.linear_v = nn.Linear(dim_in, dim_v, bias=False)

        self._norm_fact = 1 / sqrt(dim_k)

    
    def forward(self, x, mask=None):
        # x: batch, n, dim_in
        batch, n, dim_in = x.shape
        assert dim_in == self.dim_in

        q = self.linear_q(x)  # batch, n, dim_k
        k = self.linear_k(x)  # batch, n, dim_k
        v = self.linear_v(x)  # batch, n, dim_v

        dist = torch.bmm(q, k.transpose(1, 2)) * self._norm_fact  # batch, n, n
        if mask is not None:
            dist = dist.masked_fill(mask == 0, float('-inf'))
        dist = torch.softmax(dist, dim=-1)  # batch, n, n

        att = torch.bmm(dist, v)
        return att


class MultiHeadAttention(nn.Module):
    dim_in: int  # input dimension
    dim_k: int   # key and query dimension
    dim_v: int   # value dimension
    num_heads: int  # number of heads, for each head, dim_* = dim_* // num_heads

    def __init__(self, dim_in, dim_k, dim_v, num_heads=8):
        super().__init__()
        assert dim_k % num_heads == 0 and dim_v % num_heads == 0, "dim_k and dim_v must be multiple of num_heads"
        self.dim_in = dim_in
        self.dim_k = dim_k
        self.dim_v = dim_v
        self.num_heads = num_heads
        self.linear_q = nn.Linear(dim_in, dim_k, bias=False)
        self.linear_k = nn.Linear(dim_in, dim_k, bias=False)
        self.linear_v = nn.Linear(dim_in, dim_v, bias=False)
        self.out_proj = nn.Linear(dim_v, dim_in, bias=False)
        self._norm_fact = 1 / sqrt(dim_k // num_heads)

    def forward(self, x, mask=None):
        b, s, dim_in = x.shape
        assert dim_in == self.dim_in

        nh = self.num_heads
        dk = self.dim_k // nh
        dv = self.dim_v // nh
        
        q = self.linear_q(x).reshape(b, s, nh, dk).transpose(1, 2) # (b, nh, n, dk)
        k = self.linear_k(x).reshape(b, s, nh, dk).transpose(1, 2) # (b, nh, n, dk)
        v = self.linear_v(x).reshape(b, s, nh, dv).transpose(1, 2) # (b, nh, n, dk)
        
        dist = torch.matmul(q, k.transpose(2, 3)) * self._norm_fact  # batch, nh, n, n
        if mask is not None:
            mask = mask.unsqueeze(1)  # (b, 1, n, n)
            dist = dist.masked_fill(mask == 0, float('-inf'))
        dist = torch.softmax(dist, dim=-1)  # batch, nh, n, n

        att = torch.matmul(dist, v)  # batch, nh, n, dv
        att = att.transpose(1, 2).reshape(b, s, self.dim_v)  # batch, n, dim_v
        output = self.out_proj(att)
        return output

# 生成因果mask的函数
def generate_causal_mask(size):
    """
    Generate a causal (lower triangular) mask of shape (size, size).
    Args:
        size (int): The size of the square mask matrix.
    Returns:
        torch.Tensor: A lower triangular mask matrix of shape (size, size).
    """
    mask = torch.tril(torch.ones(size, size)).unsqueeze(0).unsqueeze(0)  # (1, 1, size, size)
    return mask

if __name__ == "__main__":
    # 初始化参数
    dim_in = 64
    dim_k = 64
    dim_v = 64
    num_heads = 4
    seq_length = 5
    batch_size = 2

    # 生成输入数据
    x = torch.randn(batch_size, seq_length, dim_in)  # batch_size, sequence_length, dim_in

    # 初始化自定义的MultiHeadAttention
    my_mha = MultiHeadAttention(dim_in=dim_in, dim_k=dim_k, dim_v=dim_v, num_heads=num_heads)

    # 初始化官方的nn.MultiheadAttention
    torch_mha = nn.MultiheadAttention(embed_dim=dim_in, num_heads=num_heads, bias=False)

    # 复制参数以确保两个模型的参数相同
    with torch.no_grad():
        my_mha.linear_q.weight.copy_(torch_mha.in_proj_weight[:dim_k])
        my_mha.linear_k.weight.copy_(torch_mha.in_proj_weight[dim_k:2*dim_k])
        my_mha.linear_v.weight.copy_(torch_mha.in_proj_weight[2*dim_k:3*dim_k])
        my_mha.out_proj.weight.copy_(torch_mha.out_proj.weight)

    # 将输入数据转换为官方API所需的格式
    x_torch = x.transpose(0, 1)  # (sequence_length, batch_size, dim_in)

    # 计算自定义MultiHeadAttention的输出
    my_mha_output = my_mha(x)

    # 计算官方MultiheadAttention的输出
    torch_mha_output, _ = torch_mha(x_torch, x_torch, x_torch)
    torch_mha_output = torch_mha_output.transpose(0, 1)  # 转换回 (batch_size, sequence_length, dim_in)

    # 打印输出
    print("Custom MultiHeadAttention output:")
    print(torch.sum(my_mha_output))
    print("\nTorch nn.MultiheadAttention output:")
    print(torch.sum(torch_mha_output))