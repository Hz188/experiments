/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;

    //从祖先的视角看最大值和最小值（孩子传回来->归->函数返回值）
    pair<int, int> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {INT_MAX, INT_MIN}; // 保证空节点不影响 mn 和 mx
        }
        auto [l_mn, l_mx] = dfs(node->left);
        auto [r_mn, r_mx] = dfs(node->right);
        int mn = min(node->val, min(l_mn, r_mn));
        int mx = max(node->val, max(l_mx, r_mx));
        ans = max(ans, max(node->val - mn, mx - node->val));
        return {mn, mx};
    }

public:
    int maxAncestorDiff(TreeNode *root) {
        dfs(root);
        return ans;
    }
};

// @lc code=end

