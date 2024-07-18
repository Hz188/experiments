/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        dfs(root, 0);
        return ans;
    }
private:
    int ans = 0;
    void dfs(TreeNode* root, int x) {
        if(!root) return;
        x = x*10 + root->val;
        if(!root->left && !root->right) {
            ans += x;
            return;
        }
        dfs(root->left, x);
        dfs(root->right, x);
    }
};
// @lc code=end

