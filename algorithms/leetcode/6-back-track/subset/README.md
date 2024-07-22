# 子集型回溯

## 78.子集问题回溯，每个元素都可以**选/不选**

- 站在**输入**的视角：选或者不选当前数字
  - 每个数可以在子集中，也可以不在子集中（选和不选）
  - 叶子是答案![alt text](../../../assets/imgs/algorithms/leetcode/back-track/image-1.png)
  - 回溯三问：
    - 当前操作？枚举第i个数选不选
    - 子问题？从下标>=i的数字中构造子集
    - 下一个子问题？从下标>=i+1的数字中构造子集
  - 递归链 = dfs(i) -> dfs(i+1)

- 站在**答案**的角度思考：每次必须选一个，但是要决定选哪个
  - 枚举第一个数选谁？枚举第二个数选谁？-> 多层问题，循环嵌套 + 原问题子问题，递归 = 回溯
  - 每个节点都是一个答案![alt text](../../../assets/imgs/algorithms/leetcode/back-track/image-2.png)
  - 回溯三问：
    - 当前操作？枚举下标 j>=i 的数字，加入path
    - 子问题？从下标>=i的数字中构造子集
    - 下一个子问题？从下标>=j+1的数字中构造子集
  - 递归链 = dfs(i) -> j = i, dfs(j+1),dfs(j+2),dfs(j+...),dfs(n-1)

- 未来补充：0-1背包问题也可以看做是一种子集型回溯
  

## 131.分割回文串，我们在每个字母之间加入一个逗号，这个问题就转化为了，每个逗号**选/不选**的子集问题了

- 类似于78的思路，多了一个回文的条件判断

- 站在**答案**的角度
  - 枚举回文串的位置(也就是回文串结束的位置)
  - 叶子是答案![alt text](../../../assets/imgs/algorithms/leetcode/back-track/image-3.png)
  - 回溯三问
    - 当前操作：选择回文串s[i..j]，加入path
    - 子问题？从>=i的后缀中构造回文分割
    - 下一个子问题？从>=j+1的后缀中构造回文分割
  - 递归链 = dfs(i) -> dfs(i+1), dfs(i+2),...,dfs(n)
- 站在**输入**的角度
  - 是否要枚举s[i]作为从start开始的分割出的子串的最后一个字符
  - 叶子是答案
  - 回溯三问
    - 当前操作：s[i]选或者不选作为最后一个字符，加入path
    - 子问题？从start开始，i结束构造回分割
    - 下一个子问题？从下标>=i+1的后缀中继续构造回文分割


## 练习 - 2151 最多好人数 - 看题解了

二进制枚举，这里被归为回溯问题其实是因为是子集问题，我们的答案本质上是一串0-1串是0还是1的选择问题

- [题解](https://leetcode.cn/problems/maximum-good-people-based-on-statements/solutions/1227442/er-jin-zhi-mei-ju-by-endlesscheng-ttix/)
- 由于好人数最多15个，我们可以枚举这n个人是好是坏，最多2^n次方种不同的情况
- 使用二进制来表示，枚举[0, 2^n-1]这个范围内的所有数字，判断情况i的陈述是否矛盾
  - 不矛盾则是一种答案情况，好人数的最大值即为最终答案  

## 练习 - 1601 最多换楼请求数

[题解](https://leetcode.cn/problems/maximum-number-of-achievable-transfer-requests/solutions/2500342/hui-su-by-noah-future-vkjo/)

- 方法一：输入视角（选/不选）
  - cache 表示度：出去−1， 进来+1，如果这栋楼的净变化为 0，那么 cache最后应当为 0
  - 叶子有可能是答案（因为要判断是否满足出入平衡 cache 为 0）
  - dfs(i,cnt): i 表示阶段，cnt 表示处理的请求数量
- 回溯三问
  - **当前操作？**枚举第 iii 个 request，选/不选
  - 子问题？ 从下标 ≥i 的 request 中构造子集
  - **下一个子问题？**从下表 ≥i+1 的 request 中构造子集
  - dfs(i)→dfs(i+1)
- 方法二：答案角度（枚举选哪个）
  - 每个叶子都有可能是答案
- 回溯三问
  - **当前操作？** 枚举 j≥ i的请求
  - **子问题？** 从下标 ≥ i的请求中构造答案
  - **下一个子问题？** 从下标 ≥ j+1 的请求中构造答案

## 练习 - 306 累加数

[题解](https://leetcode.cn/problems/additive-number/solutions/2455637/ling-shen-ke-hou-zuo-ye-liang-chong-hui-c2s1s/)

[题解2](https://leetcode.cn/problems/additive-number/solutions/2501628/306-lei-jia-shu-hui-su-xuan-bu-xuan-mei-h1b2p/)

- 类似分割回文子串，选择分割点

##  练习 - 93 复原IP

- answer视角看了[题解](https://leetcode.cn/problems/restore-ip-addresses/solutions/2765224/cshi-jian-ji-bai-100dai-ma-jian-ji-zhu-s-3u1i/)
- 然后根据相面的思路，input视角自己实现
  - 注意重复问题

## 练习 - 2698 惩罚数

- [题解](https://leetcode.cn/problems/find-the-punishment-number-of-an-integer/solutions/2277792/yu-chu-li-hui-su-by-endlesscheng-ro3s/)