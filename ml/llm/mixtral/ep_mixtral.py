import torch
import torch.nn.functional as F
import torch.distributed as dist
from torch .distributed import ProcessGroup
import os
import torch.multiprocessing as mp

from transformers.models.mixtral.modeling_mixtral import MixtralSparseMoeBlock, MixtralConfig, MixtralBLockSparseTop2MLP

# code is copyed from colossalai/shardformer/modeling/mixtral.py
# add some comment for learning expert parallel
class EPMixtralSparseMoeBlock(MixtralSparseMoeBlock):
    def __init__(self, config):
        self.moe_info = None
        super().__init__(config)

    def setup_ep(self, ep_group: ProcessGroup):
        ep_group = ep_group
        self.ep_size = dist.get_world_size(ep_group) if ep_group is not None else 1
        self.ep_rank = dist.get_rank(ep_group) if ep_group is not None else 0
        assert self.num_experts % self.ep_size == 0
        self.ep_group = ep_group
        self.num_experts_per_ep = self.num_experts // self.ep_size
        self.expert_start_idx = self.ep_rank * self.num_experts_per_ep
        held_experts = self.experts[self.expert_start_idx : self.expert_start_idx + self.num_experts_per_ep]
        set_tensors_to_none(self.experts, exclude=set(held_experts))
        for p in self.experts.parameters():
            p.ep_group = ep_group

    @staticmethod
    def from_native_module(module: MixtralSparseMoeBlock, *args, **kwargs) -> "EPMixtralSparseMoeBlock":
        LazyInitContext.materialize(module)
        module.__class__ = EPMixtralSparseMoeBlock
        # if "ep_group" in kwargs:
        assert "ep_group" in kwargs, "You should pass ep_group in SubModuleReplacementDescription via shard_config!!"
        module.setup_ep(kwargs["ep_group"])
        return module

    def forward(self, hidden_states: torch.Tensor) -> torch.Tensor:
        
        batch_size, sequence_length, hidden_dim = hidden_states.shape  # (1, 3, 8)
        
        hidden_states = hidden_states.view(-1, hidden_dim)  # (3, 8)
        
        # router_logits: (batch * sequence_length, n_experts)
        router_logits = self.gate(hidden_states)  # （3, 4） 假设4个专家 ep_size=2, r0:e0,e1 r1:e2,e3

        routing_weights = F.softmax(router_logits, dim=1, dtype=torch.float)  # (3, 4)

        # (3, 2)  每个token选了2个专家 [[t00, t01], [t10, t11], [t20, t21]]
        # t_i_{0,1}: token i 选则的第 0 or 1 个专家
        routing_weights, selected_experts = torch.topk(routing_weights, self.top_k, dim=-1) # (3, 2) (3, 2)

        routing_weights /= routing_weights.sum(dim=-1, keepdim=True)   # weight norm 
        # we cast back to the input dtype
        routing_weights = routing_weights.to(hidden_states.dtype)

        # (3, 2) -> (2, 3) -> (6,) 
        # [t00, t10, t20, t01, t11, t21] 
        # 分别是t0 t1 t2 的一顺位专家 t0 t1 t2 的二顺位专家
        # eg: [2,2,2,0,3,0] 数组下标是token id 数组元素是 专家id
        selected_experts = selected_experts.t().reshape(-1) 
        
        # 按专家id排序，取arg，得到对应的token id
        # eg: [0,0,2,2,2,3] -> [3,5,0,1,2,4] 这个数组内容是token id，通过token id可以索引到专家id
        selected_experts_idx = selected_experts.argsort()
        
        # (3,2) -> (6,2) [t0, t1, t2, t0, t1, t2]
        # hidden_states.repeat()[3] 含义就是：token id = 3，即在selected_experts中的索引是3，对应专家id=0，其输入是hidden_states[3]
        # hidden_states.repeat()[5] 含义就是：token id = 5，即在selected_experts中的索引是5，对应专家id=0，其输入是hidden_states[5]
        # hidden_states.repeat()[0] 含义就是：token id = 0，即在selected_experts中的索引是0，对应专家id=2，其输入是hidden_states[0]
        # hidden_states.repeat()[1] 含义就是：token id = 1，即在selected_experts中的索引是1，对应专家id=2，其输入是hidden_states[1]
        # hidden_states.repeat()[2] 含义就是：token id = 2，即在selected_experts中的索引是2，对应专家id=2，其输入是hidden_states[2]
        # hidden_states.repeat()[4] 含义就是：token id = 4，即在selected_experts中的索引是4，对应专家id=3，其输入是hidden_states[4]
        # 整体意思：
        #   通过token id，得到对应的token states
        #   而这个token id是按专家id排序的，所以这样放置后的states也是按专家id排序的，专家号越小 states越靠前）
        dispatch_states = hidden_states.repeat(self.top_k, 1)[selected_experts_idx] 

        input_split_sizes = selected_experts.bincount(minlength=self.num_experts)  # (4,) 统计当前rank中3个token选出的6个专家，每个专家几个token [2,0,3,1] 表示专e0 2个 e1 0个，e2 3个 e3 1个

        # ep=2, 4个专家 也就是
        # r0: e0 e1
        # r1: e2 e3
        output_split_sizes = torch.zeros_like(input_split_sizes)  #  (4, )  

        # [2,0,3,1] [2,0,3,1] -> [2,0,2,0] [3,1,3,1]
        # all_to_all_single: 先split张量，再scatter给所有进程，然后再concat为一个张量
        # 文字解释一下：
        #   rank0上是 2 0 3 1 e0 e1，所以要处理的输入就是 2 0，3 1是 e2 e3的输入，在rank1上，要发送过去
        #   rank1上是 2 0 3 1 e2 e3，所以要处理的输入就是 3 1，2 0是 e0 e1的输入，在rank0上，要发送过去
        #   同样的 rank0 和 rank1 也会接收对方发来的输入
        dist.all_to_all_single(output_split_sizes, input_split_sizes, group=self.ep_group)  

        # [2,0,3,1] -> [[2,0], [3,1]] -> [2, 4]  all_to_all_uneven的输入token情况分别是r0 2个和r1 4个
        # 文字解释：
        #       这里相当于统计的是rank上处理几个token，没有细分到rank上具体的专家处理几个token，即 rank0 6个里处理两个，rank1 6个里处理4个
        #       rank0上的e0和e1具体处理哪几个token，通过下方output_split_sizes.view().tolist()得到的
        input_split_list = input_split_sizes.view(self.ep_size, self.num_experts_per_ep).sum(dim=-1).tolist()
        
        # [2, 0, 2, 0] -> [[2,0], [2,0]] -> [2, 2] 
        # [3, 1, 3, 1] -> [[3,1], [3,1]] -> [4, 4]
        # all_to_all_uneven的接收token的切分情况分别是 
        #   r0: [2,2] r0从r0取2个 从r1取2个
        #   r1: [4,4] r1从r0取4个 从r1取4个
        output_split_list = output_split_sizes.view(self.ep_size, self.num_experts_per_ep).sum(dim=-1).tolist()
        
        # 关键通信来了：
        #   根据 input_split_list [2, 4]
        #   切分 dispatch_states  [6, h] -> [2, h], [4, h] -> 发送
        #       rank0 发送 [4, h] 收 [2, h] -> 最终 output_states = [4, h]
        #       rank1 发送 [2, h] 收 [4, h] -> 最终 output_states = [8, h]
        # 这步完成后，每个rank的专家得到自己的输入token了 
        output_states, _ = all_to_all_uneven(dispatch_states, input_split_list, output_split_list, self.ep_group)  # [4, h] [8, h] 
        
        # compute expert output
        # 非MoE参数的梯度要缩放回去 grad = grad * ep_size
        output_states = MoeInGradScaler.apply(output_states, self.ep_size)  #   (4, h) (8, h) 
        if output_states.size(0) > 0:
            if self.num_experts_per_ep == 1:
                # ep_size = ep_num 每个rank只有一个专家，所以直接计算
                # 不需要将output_state继续split
                expert = self.experts[self.expert_start_idx]
                output_states = expert.act_fn(expert.w1(output_states)) * expert.w3(output_states)
                output_states = expert.w2(output_states)
            else:
                # ep_size < ep_num 每个rank有多个专家
                # 那么output_state就需要split，得到每个专家需要的子部分
                
                # 前面有output_split_size
                #   rank0 [2,0,2,0]
                #   rank1 [3,1,3,1]
                # 含义是
                #   rank0上目前 output_states (4, h) 要分为 2份 0份 2份 0份 作为对应专家的输入
                #   rank0上目前 output_states (8, h) 要分为 3份 1份 3份 1份 作为对应专家的输入
                output_states_splits = output_states.split(output_split_sizes.tolist())
                output_states_list = []
                for i, split_states in enumerate(output_states_splits): 
                    if split_states.size(0) == 0:
                        continue
                    # %号是用来取模，因为本地专家的输入有两部分：一部分来源于本地，一部分来源于其他rank通信
                    #   rank0 2, 0, 2, 0 前两个 2 0 是来源于本地的输入，后两个 2 0 是来源于其他rank通信过来的输入
                    #   rank1 3, 1, 3, 1 前两个 3 1 是来源于rank0通信过来的输入，后两个 3 1 是来源于其他rank通信过来的输入
                    expert = self.experts[self.expert_start_idx + i % self.num_experts_per_ep]
                    split_states = expert.act_fn(expert.w1(split_states)) * expert.w3(split_states)
                    split_states = expert.w2(split_states)
                    output_states_list.append(split_states)
                output_states = torch.cat(output_states_list) # (4, h) (8, h)
        
        # MoE参数的梯度要在EP size上规约 grad = grad / ep_size
        output_states = MoeOutGradScaler.apply(output_states, self.ep_size)  
        
        # input_split_list
        #   rank0  (2, 4)
        #   rank1  (2, 4)
        # output_split_list
        #   rank0  (2, 2) 
        #   rank1  (4, 4)
        # 注意下面调用input_split_list 和 output_split_list换位置了：也就是将states按output进行split发送，按input进行接收
        # output_states 
        #   rank0  (4, h) -> (2, 2) 切 发后2
        #   rank1  (8, h) -> (4, 4) 切 发前4
        # 最终 dispatch_states
        #   rank0  (6, h)
        #   rank1  (6, h) 
        dispatch_states, _ = all_to_all_uneven(output_states, output_split_list, input_split_list, self.ep_group)  # 专家处理完对应token的输出，要返还回去给别的rank
        
        # 注意这里的dispatch states
        #   顺序是 token 按 专家id 排序的放置顺序
        #   我们需要恢复到原来的token顺序
        
        recover_experts_idx = torch.empty_like(selected_experts_idx)  # (6,)
        # selected_experts_idx = [3,5,0,1,2,4]  里面的值是 token id 通过selected_experts[token id] 可以得到 专家id，是一个映射
        # 按索引[3,5,0,1,2,4] 将[0,1,2,3,4,5] 放入 -> [2,3,4,0,5,1]
        # 含义是:
        #   token id = 0，其对应的输入是dispatch states[2] 应该放回到 dispatch states[0]的位置
        #   token id = 1，其对应的输入是dispatch states[3] 应该放回到 dispatch states[1]的位置
        #   token id = 2，其对应的输入是dispatch states[4] 应该放回到 dispatch states[2]的位置
        #   token id = 3，其对应的输入是dispatch states[0] 应该放回到 dispatch states[3]的位置
        #   token id = 4，其对应的输入是dispatch states[5] 应该放回到 dispatch states[4]的位置
        #   token id = 5，其对应的输入是dispatch states[1] 应该放回到 dispatch states[5]的位置
        recover_experts_idx[selected_experts_idx] = torch.arange(   
            selected_experts_idx.size(0), device=selected_experts_idx.device
        )

        # t_i的含义是 token i 经过对应专家计算后的输出，前三个是对应每个token选出的第一个专家计算的结果，后三个是每个token选的第二个专家计算的结果
        # 重新恢复顺序 [t00, t10, t20, t01, t11, t21]  
        dispatch_states = dispatch_states[recover_experts_idx] 

        # 重新恢复顺序 [[t00,t10,t20], [t01,t11,t21]] 前一组是一顺位专家计算后的结果，后一组是二顺位专家计算后的结果
        k_hidden_states = dispatch_states.chunk(self.top_k)  # （2, 3)

        # t00 要和 t01  合并为最终的 t0
        # t10 要和 t11  合并为最终的 t1
        # t20 要和 t21  合并为最终的 t2
        output_states = k_hidden_states[0] * routing_weights[:, 0, None] # (1, 3) * (1, 3)  计算完一列了
        for i in range(1, self.top_k):
            output_states += k_hidden_states[i] * routing_weights[:, i, None]  # 后面的每次计算结果都加到上面的那一列中
        output_states = output_states.reshape(batch_size, sequence_length, hidden_dim)
        return output_states, router_logits


def run_all_to_all_single(rank, world_size):
    os.environ['MASTER_ADDR'] = 'localhost'
    os.environ['MASTER_PORT'] = '12355'
    # 初始化进程组
    dist.init_process_group("nccl", rank=rank, world_size=world_size)
    torch.cuda.set_device(rank)

    # 每个进程创建一个张量，将其数值设置为其rank值
    torch.manual_seed(1435+rank)
    weights = torch.randn(2, 4).cuda()
    routing_weights, selected_experts = torch.topk(weights, k=2, dim=-1)

    # 为接收张量分配空间
    print(f'Rank {rank} selected experts: {selected_experts}')
    selected_experts = selected_experts.t().reshape(-1)


    # 执行 all-to-all 单张量通信
    input_split_sizes = selected_experts.bincount(minlength=4)

    # 打印发送前的tensor
    print(f'Rank {rank} before all_to_all_single: {input_split_sizes}')

    output_split_sizes = torch.zeros_like(input_split_sizes)
    dist.all_to_all_single(output_split_sizes, input_split_sizes)

    # 打印接收到的tensor
    print(f'Rank {rank} after all_to_all_single: {output_split_sizes}')

    # 清理进程组
    dist.destroy_process_group()

if __name__ == "__main__":
    world_size = 4  # 假设有4个进程
    mp.spawn(run_all_to_all_single, args=(world_size,), nprocs=world_size, join=True)
