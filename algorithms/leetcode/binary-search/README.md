# Binary Search 红蓝染色法

对于当前数组：[left, mid, right]

- false: [left, mid] 红色，表示不满足某种target条件
- true: [mid, right] 蓝色，表示满足某种target条件

所以while循环中，[left, right]是未染色区间，然后每次mid询问，都可以对一半区间染色

- 或者是左半区间染红
- 或者是右半区间染蓝

## Example

34.left_bound题目

- 红色：< target的元素
- 蓝色：>= target的元素
- 每次询问mid，**和target比较**
  - 红色：mid < target，则[left...mid] < target， 全染红
  - 蓝色：mid >= target，则[mid...right] >= target，全染蓝
- 更新left或者right，其语义是：剩余的还未染色的区间

162.findPeak题目

- 红色：在peak左侧的元素
- 蓝色：peak元素或者peak右侧元素
- 每次询问mid，**和mid+1比较**
  - 红色：mid在peak左侧，则[left...mid]均在peak左侧，全染红
  - 蓝色：mid是peak或者在peak右侧，则[mid...right]均在peak右侧，全染蓝
- 更新left或者right，其语义是：剩余的还未染色的区间

153.旋转排序数组的最小值

- 红色：在最小值左侧的元素
- 蓝色：最小值或者最小值右侧元素
- 每次询问mid，**和right比较**
  - 红色：mid大于n-1，mid在最小值左侧，那么[left...mid]全在最小值左侧，全染红
  - 蓝色：mid小于n-1，mid是最小值或者最小值右侧，那么[mid...right]全在最小值右侧，全染蓝
- 更新left或者right，其语义是：剩余的还未染色的空间

33.旋转数组搜索值

- 红色：在target左侧的元素
- 蓝色：target或者target右侧元素
- 每次询问mid，**和target比较**
  - 这里的比较条件除了和target比，同时还要和end比，确定在rotate的哪一段中
  - 蓝色：有三种情况为蓝色，看33.题注释
  - 红色：剩余情况为红
- 更新left或者right，其语义是：剩余的还未染色的空间
