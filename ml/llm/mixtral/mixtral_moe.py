# %%
import torch
import torch.nn as nn
from transformers.models.mistral.modeling_mistral import MistralModel 
from transformers.models.mixtral.modeling_mixtral import MixtralModel, MixtralSparseMoeBlock, MixtralConfig, MixtralBLockSparseTop2MLP


config = MixtralConfig(hidden_size=4, intermediate_size=8, num_local_experts=4, num_experts_per_tok=2)
moe_block = MixtralSparseMoeBlock(config)

input = torch.randn(2, 5, 4)
final_hidden_states, router_logits = moe_block(input)
final_hidden_states.shape, router_logits


# %%
'''
路由过程放在MoEBlock内部了

FWD过程
先路由
1. hidden先reshape 到(b * s, h) -> 然后过gate 得到 (b*s, n_exp) logits
2. logits过softmax得到weight
3. 然后选top_k
    routing_weights, selected_experts = torch.topk(routing_weights, self.top_k, dim=-1)
    返回值是对应的专家的weights和对应的索引号
再计算
4. 得到token的mask
5. for循环取出一个专家
    5.1 通过索引转换，只计算分配给这个专家的token
    5.2 然后通过index_add_，对应位置去做加法
6. reshape回 b s h形状
返回
7. 隐层状态，路由的logits两个返回值

'''

# %%
index = [ [0, 2],
         [0, 1],
        [3, 2],
        [3, 1],
        [0, 1],
        [0, 2],
        [3, 0],
        [2, 1],
        [0, 3],
        [1, 0]]  # (10, 2)
index = torch.tensor(index)
mask = torch.nn.functional.one_hot(index, num_classes=4)
expert_mask = mask.permute(2,1,0)
mask.shape, expert_mask  # torch.Size([10, 2, 4]), torch.Size([4, 2, 10]))
# 10,2,4: 10个token，每个token有两个one-hot向量，每个one-hot从4个里选了1个专家，即10个token每个选了两个专家
# 4,2,10: 4个专家，有两个长度10的列表，列表被0-1填充，代表每个专家要处理10个token中的哪几个
# %%
idx, top_x = torch.where(expert_mask[0])
idx, top_x  # 一个是行号，一个是列号
# (tensor([0, 0, 0, 0, 0, 1, 1]), tensor([0, 1, 4, 5, 8, 6, 9]))
# %%
a = torch.arange(16).reshape(8,2)
a[None, [1,2,5,6]].reshape(-1, 2)
# %%
a.index_add(0, torch.tensor([1,2,5,6]), torch.ones(4,2, dtype=torch.long))
# %%
# torch where对0-1张量的作用是，返回1的横坐标和纵坐标
torch.where(torch.tensor([[1,1,0,0]]))
# %%
# 具体注释

class MixtralSparseMoeBlock(nn.Module):
    def __init__(self, config):
        super().__init__()
        self.hidden_dim = config.hidden_size
        self.ffn_dim = config.intermediate_size
        self.num_experts = config.num_local_experts
        self.top_k = config.num_experts_per_tok    
        self.gate = nn.Linear(self.hidden_dim,self.num_experts,bias=False)
        self.experts = nn.ModuleList([MixtralBLockSparseTop2MLP(config) for _ in range(self.num_experts)])

    def forward(self, hidden_states: torch.Tensor) -> torch.Tensor:
        # 取出shape  [batch,seq_len,hidden_dim] 假设是 [2,10,512]
        batch_size, seq_len, hidden_dim = hidden_states.shape
        # batch和seq_len变一个维度 [b,s,h] -> [b*s,h] [20,512]
        hidden_states = hidden_states.view(-1, hidden_dim)
        '''
            gate shape: [hidden_dim,num_experts] [512,8]
            [b*s,h] -> [b*s,h]   [20,8] 每个token都对应8个expert 
        '''
        router_logits = self.gate(hidden_states)
        # softmax 注意是在专家维度，路由到8个专家的概率值被归一化 shape: [20,8]
        routing_weights = F.softmax(router_logits, dim = 1,dtype=torch.float)
        
        # 取出前两个概率值高的expert 还是在专家维度选两个 shape: [20,2]
        # routing_weights: [20,2] seleted_experts: [20,2] topk这个函数是不连续的说明不可导 但是取出来的routing_weights是有梯度的，bp的时候更新这个参数
        routing_weights,seleted_experts = torch.topk(routing_weights,self.top_k,dim=-1)
        
        # 对weight进行平均求和 routing_weights: [20,2]
        routing_weights = routing_weights / routing_weights.sum(dim=-1, keepdim=True).to(hidden_states.dtype)
        # 初始化矩阵 final_hidden_states: [20,512]
        final_hidden_states = torch.zeros(
            (batch_size * seq_len, hidden_dim),dtype=hidden_states.dtype
        )
        # 获取mask 为了计算效率,具体做法是遍历每个专家，把每个专家负责的token一次计算完
        # seleted_experts: [20,2] 此时one_hot加了个维度8 --> [20,2,8] 由于我们需要遍历专家进行计算--> [8,2,20]
        expert_mask = nn.functional.one_hot(seleted_experts,num_classes=self.num_experts)
        # [20,2,8] ---> [8,2,20]
        expert_mask = expert_mask.permute(2,1,0)
        # 开始遍历专家
        for expert_idx in range(self.num_experts):
            # 取出索引为expert_idx的专家,self.experts是个list
            expert_layer = self.experts[expert_idx]
            # 通过where函数拿到需要被第0个专家计算的token的索引 注意我们这里假设是20个token，idx代表的是20个token的索引
            # 比如20个token中，第5、7、9个token被选中了，以及top_x是代表idx在哪一行，前面我们是取了top2个专家出来
            idx,top_x = torch.where(expert_mask[expert_idx])

            # 转为list
            top_x_list = top_x.tolist()
            idx_list = idx.tolist()

            # 把原始hidden_states的值通过top_x_list取出来，可以把hidden_states理解成词向量: [20,512]
            # 注意这里用None加了一个维度，实际还是从 [20,512] 20里面取，也就是取哪一个token
            current_state = hidden_states[None,top_x_list].reshape(-1,hidden_dim)
            # 注意这里把原始词向量的某些token的词向量取出来，过了专家层再与路由权重相乘
            current_hidden_states = expert_layer(current_state) * routing_weights[top_x_list,idx_list]
            # 添加到final_hidden_states 第0个维度 索引 添加的权重
            final_hidden_states.index_add_(0,top_x,current_hidden_states)
        final_hidden_states.reshape(batch_size,seq_len,hidden_dim)
        return final_hidden_states,router_logits