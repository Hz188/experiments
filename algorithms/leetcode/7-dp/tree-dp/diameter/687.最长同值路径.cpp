/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int ans = 0;
    int dfs(TreeNode* root) {
        if(!root) return -1;

        int val = root->val;
        int l = dfs(root->left) + 1;
        int r = dfs(root->right) + 1;
        int cur = 0;
        int ret = 0;
        if(root->left && root->left->val == val) {
            cur += l;
            ret = l;
        }
        if(root->right && root->right->val == val) {
            cur += r;
            ret = max(ret, r);
        }
        ans = max(cur, ans);
        return ret;
    }
};
// @lc code=end

