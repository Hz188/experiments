# Breadth First Search

## BFS的模板一：两个数组

通过移动语义，两个数组交换来实现BFS

```c++
vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    vector<TreeNode*> cur = {root};
    while (cur.size()) {
        vector<TreeNode*> nxt;
        vector<int> vals;
        for (auto node : cur) {
            vals.push_back(node->val);
            if (node->left)  nxt.push_back(node->left);
            if (node->right) nxt.push_back(node->right);
        }
        cur = move(nxt);
        ans.emplace_back(vals);
    }
    return ans;
}
```

## BFS的模板二：一个队列

```c++
vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        vector<int> vals;
        for (int n = q.size(); n--;) {
            auto node = q.front();
            q.pop();
            vals.push_back(node->val);
            if (node->left)  q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.emplace_back(vals);
    }
    return ans;
}
```