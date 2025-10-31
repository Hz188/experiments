import numpy as np
import paddle

data = [100]
shape = (3,4,5)
data.extend([3, *shape, 2, 2])
print(data)
data_tensor = paddle.to_tensor(data)
print(np.prod(data_tensor.shape))