# Queue

## Monotonic queue

### 239 滑动窗后的最大值

需要一个什么样的数据结构？单调队列

- 双端队列
  - 移除最左边的元素
  - 移除最右边的元素
  - 在最右边插入元素
- 单调性
  - 对队首到队尾单调递减

16字总结：及时去掉无用数据，保证双端队列有序

- 当数字 >= 队尾，弹出队尾（**和单调栈一样**）
- 弹出队首**不在窗口内**的元素