# Two Pointer

## N-Sum问题中的一个常见优化点(N >= 3)

主要优化方向就是去重和有序数组的边界条件利用 for i in range(0, n-2)

- 优化1：nums[i] + nums[i+1] + nums[i+2] > target
  - 目前的最小和大于target了，后面怎么选都更大，可以直接break（求target的情况）或者更新答案（最接近target的情况）
- 优化2：nums[i] + nums[n-2] + nums[n-1] < target
  - 目前的最大和小于target了，后面怎么选都更小，可以直接break或者更新答案
- 优化3：i > 0 && nums[i] == nums[i-1]
  - 当前值和上一个值相同，那么情况完全一样，直接continue


## 接雨水

主要技巧 前后缀最大值数组的使用

- 前缀最大值 pre_max[i] = max(nums[i], pre_max[i-1])
- 后缀最大值 suf_max[i] = max(nums[i], suf_max[i+1])

对比前缀和数组 pre_sum[i]

- 前缀和 
  - pre_sum[0] = 0
  - [0...i]: pre_sum[i+1] = pre_sum[i] + nums[i]
  - sum[i...j] = sum[0...j] - sum[0...i) = pre_sum[j+1] - pre_sum[i]