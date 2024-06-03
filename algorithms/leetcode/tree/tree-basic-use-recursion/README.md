# Tree Basic: Use Recursion

这里就是使用递归的一些习题，记录一些我觉着有收获的点

## 199题 右视图

- 通过数组size和当前遍历深度问题，将一些层序遍历解法转换为了递归解法

```c++
    if(!root) return;
    if (depth == ans.size()) {
        ans.push_back(root->val);
    }
    dfs(root->right, depth+1);
    dfs(root->left, depth+1);
```

## 信息传递

1026题目的几种解法说明了下面两个问题

- 后序遍历，我们从孩子处获得信息，然后汇总 -> 自底向上 -> 通过返回值获得子树信息
- 前序遍历，我们从父亲获得信息，给孩子，然后汇总 -> 自顶向下 -> 通过函数参数传递父亲信息
