# 前缀和

```c++
auto pre_sum = vector(nums.size() + 1, 0);
for(int i = 0; i < nums.size(); i++){
    pre_sum[i+1] = nums[i] + pre_sum[i];  // pre_sum [i+1] = [0..i+1)
}
```

## 进阶：前缀和 + 哈希表

```c++
int n = nums.size();
auto pre_sum = vector<int>(n+1, 0);
auto val_to_idx = unordered_map<int, int>{};
for(int i = 0; i < n; i++) {
    pre_sum[i+1] = pre_sum[i] + nums[i];
    val_to_idx[pre_sum[i+1]] = i+1;
}
for (int i = 0; i < n; i++) {
    int need = pre_sum[i+1] - target;
    if (valToIndex.count(need)) {
        // nums[valToIndex[need]...i] 就是和为 target 的子数组
    }
}
```

- 根据题目 need的形式可能发生变化
    - 可能是作差
    - 可能是取%
- 然后是如果题目要最长长度
    - 如果有多个情况key相同，那么哈希表存的是第一个key对应的索引
    - 这样肯定大于后面的相同key的长度