/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        dfs(root, 0);
        return root ? ans : 0;
    }

private:
    int ans = INT_MAX;

    void dfs(TreeNode* root, int level) {
        if(!root) return;
        level++;
        //优化:最优性剪枝
        if(level > ans) return;
        if(!root->left && !root->right) {
            ans = min(ans, level);
            return;
        }
        dfs(root->left, level);
        dfs(root->right, level);
    }
};
// @lc code=end

