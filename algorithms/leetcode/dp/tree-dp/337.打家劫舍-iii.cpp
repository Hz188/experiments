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
using namespace std;
class Solution {
public:
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res[0], res[1]);
    }

    vector<int> dfs(TreeNode* root) {
        if(!root) return {0, 0}; 
        auto l = dfs(root->left);
        auto r = dfs(root->right);

        int rob = l[1] + r[1] + root->val;
        int not_rob = max(l[0], l[1]) + max(r[0], r[1]);            

        return {rob, not_rob};

    }
};
// @lc code=end

