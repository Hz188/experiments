# Sliding Window

## Template 1

```c++
int n = sequence.length();
int left = 0;
// window span [left, right]
for(int right = 0; right < n; right++){
    //1. expand the window to satisify the question

    while(satisfy the question -> dissatisfy the question ) {
        //2. record answer here
        ans = min or max(ans, f(left, right));
        //3. Shrink the window 
    }
    //2. or record answer here
}
```

## Tepmpalte 2

```c++
int n = sequence.length();
int left = 0;
// window span [left, right]
for(int right = 0; right < n; right++){
    //1. expand the window to satisify the question

    while(dissatisfy the question -> satisfy the question ) {
        //2. Shrink the window 
    }
    //3. record answer here
    ans = min or max(ans, f(left, right));
}
```

## Summary

找出题意中某种“单调性”，只有满足了单调性，才可以使用双指针

- 209题：比如[l...r] > target了，数组值全为正，那么[l...r+1]肯定接着变大，大于target
  - right在移动时候，子数组和是在不断变大的，越来越大，到满足条件（**这就是单调性**）
  - while条件从**满足要求不断地变到了不满足要求**
    - 数组越长**越能满足**，所以left开始移动了，让while从满足->不满足
  - 此时right就要接着移动了，处理新的右边界，来继续满足要求
- 713题：是另一种情形，while条件从**不满足要求一直变到满足要求**，也就是说数组越长**越不满足**（单调性）
  - right在移动的时候，积是抽调不断变大的，越来越大，大到不能满足条件（**本题的单调性**）
  - while条件才**不满足要求不断地变到了满足要求**
    - 数组越长越不满足，所以left开始移动，让while从不满足->满足，跳出循环
  - 记录满足的答案
  - 然后right接着移动了，处理新的右边界
- 3题：
  - right在移动的时候，窗口内容增多，字符频率逐渐增大，大到**不满足条件**（单调性）
  - while条件**从不满足到满足**
    - 窗口越长越不满足，此时left开始移动，让while从不满足->到满足，跳出循环
  - 记录答案
  - 然后right接着移动，窗口接着扩大，到不满足，处理新的右边界

## Practice

- 2958题：同第3题，情形一模一样

- 2730题：要找最长**半重复**子串，翻一下：要找最长满足条件的结果
  - right不断移动，相邻重复0个1个，满足，2个，不满足，所以随着right的移动，是走向越来越不满足的（**单调性**）
  - 这个时候要移动left了，让不满足 -> 满足，跳出while循环
  - 记录答案

- 1004题：走向不满足的方向
  - right不断移动，0 的个数增加，1个，可翻转，2个可翻转，等等等到k个，可翻转，然后k+1个时候，不可翻转，不满足了，所以也是走向越来越不满足
  - 这个时候要移动left了，让不满足 -> 满足
  - 记录答案

- 2962题：走向满足的方向
  - right不断移动，最大元素次数从0 1 2 ... 到k，开始满足条件，是越来越满足
  - 这个时候移动left，while从 满足 -> 不满足
  - 记录答案：如果当前[left,right]满足，[0,right],[1,right]...[left,right]都是满足的（**单调性**）
    - 所以while跳出循环的时候，是刚刚[left,right]不满足，而[left-1,right]满足，那么[0...left-1,right]都满足

- 2302题：走向不满足的方向
  - right不断移动，区间和变大，区间长度变大，那么乘积变大，从满足，到不满足
  - 这个时候移动left，从不满足到满足
  - 记录答案：如果当前[left,right]满足那么[left+1, right] ... [right, right]也满足（**单调性**）

- 1658题：题目是两边移除元素，要求移除的最少，让x=0 (**正难则反**)
  - 那么等价于，找最长的连续数组，让其和为sum-x，就转换为了找和为target的最长连续子数组的长度了

- 1234题：题意是QWER四个字符出现的次数都是m = 4 / n
  - 形象化理解：我们有四个水桶，分别装QWER，容量都是m，需要每个都填满，不多不少
  - 现在我们有些桶没装满，有些桶溢出了，需要一些替换操作，将多的桶中的比如说Q，换成少的桶中的比如说R
