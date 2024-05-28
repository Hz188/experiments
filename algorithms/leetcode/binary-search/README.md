# Binary Search 红蓝染色法

## 闭区间形式原理详解

对于当前数组：[left, mid, right]

- false: [left, mid] 红色，表示 < target
- true: [mid, right] 蓝色，表示 >=target

所以while循环中，[left, right]是未染色区间，然后每次mid询问，都可以对一半区间染色

- 或者是左半区间染红
- 或者是右半区间染蓝

循环不变量 ：left 和 right 双指针的语义永远在更新时候维持不变

- [left, right] -> 是我们还未染色的区间
- left - 1 -> 染红色的区间
- right + 1 -> 染蓝色的区间

结束循环时left = right + 1，所以

- 蓝色区间开始位置也就是left，即[left...] or [right+1...]是蓝色
- 红色区间结束位置也就是right，即[...right] or [...left-1]是红色

## 三种区间形式对比

| 区间形式          | 左闭右闭                          | 左闭右开                       | 左开右开                     |
| ----------------- | --------------------------------- | ------------------------------ | -------------------------- |
| 区间开始条件      | `left=0,right=n-1`                | `left=0,right=n`               | `left=-1,right=n`            |
| 循环条件          | `while(left <= right)`            | `while(left < right)`          | `while(left+1<right)`       |
| 当前数组          | `[left,mid,right]`                | `[left,mid,right)`             | `(lef,t mid, right)`         |
| `cond(mid)=false` | `[left, mid]` 染红,`left=mid+1`   | `[left, mid]`染红,`left=mid+1` | `(left,mid]`染红,`left=mid`  |
| `cond(mid)=true`  | `[mid, right]` 染蓝,`right=mid-1` | `[mid, right)`染蓝,`right=mid` | `(left,mid]`染蓝,`right=mid` |
| 循环结束条件      | `left = right +1`                   | `left == right`               | `left+1 == right` |
| left循环不变量    | `[...left-1/right]`始终是红色        | `[...left-1/right-1]`始终是红色 | `[...left/right-1]`始终是红色         |
| right循环不变量   | `[left/right+1...]`始终是蓝色       | `[left/right...]`始终是蓝色      | `[left+1/right...]`始终是蓝色       |

## 四种不同的查找类型

| 目标target的查找类型 |  |
| ---- | ---- |
| 1. `>=target` | `>=8`     |
| 2. `>target` |  整数数组`>8`可以看做`>=8+1`转换为1.    |
| 3. `<target` | 整数数组`<8`可以看做`(>=8)`左边那个数，也就是`(>=8)索引-1`，转换为1     |
| 4. `<=target` |  整数数组`<=8`可以看做`>8`左边那个数，也就是`(>8)索引-1`，先转换为2再转换为1|

## 有序数组

34.left_bound题目

- 红色：< target的元素
- 蓝色：>= target的元素
- 每次询问mid，**和target比较**
  - 红色：mid < target，则[left...mid] < target， 全染红
  - 蓝色：mid >= target，则[mid...right] >= target，全染蓝
- 更新left或者right，其语义是：剩余的还未染色的区间
- 所以最终返回值是：right + 1，而right + 1 结束while 循环时候 == L，所以返回L也可

## 无序数组

162.findPeak题目

- 红色：在peak左侧的元素
- 蓝色：peak元素或者peak右侧元素
- 每次询问mid，**和mid+1比较**
  - 红色：mid在peak左侧，则[left...mid]均在peak左侧，全染红
  - 蓝色：mid是peak或者在peak右侧，则[mid...right]均在peak右侧，全染蓝
- 更新left或者right，其语义是：剩余的还未染色的区间

## 旋转数组

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
