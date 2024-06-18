'''
FWD过程

'''
# %%
import torch
import torch.nn as nn
from transformers import AutoTokenizer, AutoModelForCausalLM, GenerationConfig

# %%  官方demo

model_name = "/mnt/jfs-hdd/share/models/deepseek-moe-16b-base"
tokenizer = AutoTokenizer.from_pretrained(model_name)
model = AutoModelForCausalLM.from_pretrained(model_name, torch_dtype=torch.bfloat16, device_map="auto", trust_remote_code=True)
model.generation_config = GenerationConfig.from_pretrained(model_name)
model.generation_config.pad_token_id = model.generation_config.eos_token_id

text = "An attention function can be described as mapping a query and a set of key-value pairs to an output, where the query, keys, values, and output are all vectors. The output is"
inputs = tokenizer(text, return_tensors="pt")
outputs = model.generate(**inputs.to(model.device), max_new_tokens=100)

result = tokenizer.decode(outputs[0], skip_special_tokens=True)
print(result)

# %% 
from deepseek_file.configuration_deepseek import DeepseekConfig
from deepseek_file.modeling_deepseek import DeepseekMoE

config = DeepseekConfig(hidden_size=4, intermediate_size=8, moe_intermediate_size=2, n_routed_experts=6, n_shared_experts=2, num_experts_per_tok=2)
moe_block = DeepseekMoE(config)

input = torch.randn(2, 5, 4)
out = moe_block(input)
out.shape

# %%
moe_block


# %%