/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
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
#include <functional>
#include <tuple>
using namespace std;
class Solution {
public:
    int rob(TreeNode* root) {
        auto [rob_root, not_rob_root] = dfs(root);
        return max(rob_root, not_rob_root);
    }

    tuple<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0}; 
        auto [rob_l, not_rob_l] = dfs(root->left);
        auto [rob_r, not_rob_r] = dfs(root->right);

        int rob_root = not_rob_l + not_rob_r + root->val;
        int not_rob_root = max(rob_l, not_rob_l) + max(rob_r, not_rob_r);            

        return {rob_root, not_rob_root};

    }
};
// @lc code=end

