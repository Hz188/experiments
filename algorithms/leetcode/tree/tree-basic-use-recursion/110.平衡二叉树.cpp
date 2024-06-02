/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        return get_height(root) != -1;
    }
    int get_height(TreeNode* root) {
        if (!root)  return 0;

        int left_height = get_height(root->left);
        if(left_height == -1) return -1;
        int rigth_height = get_height(root->right);
        if(rigth_height == -1 || abs(rigth_height - left_height) > 1) {
            return -1;
        }

        return 1 + max(left_height, rigth_height);
    }
};
// @lc code=end

