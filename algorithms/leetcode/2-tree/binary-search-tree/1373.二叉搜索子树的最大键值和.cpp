/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
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
#include <tuple>
using namespace std;
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }

private:
    int ans = 0;
    tuple<int, int, int> dfs(TreeNode* root) {
        if(!root) return {INT_MAX, INT_MIN, 0};

        auto [l_min, l_max, l_sum] = dfs(root->left);
        auto [r_min, r_max, r_sum] = dfs(root->right);
        int x = root->val;
        if(x <= l_max || x >= r_min) { // not BST
            return {INT_MIN, INT_MAX, 0};
        } //else: x > l_max && x < r_min
        int s = l_sum + r_sum + x;
        ans = max(s, ans);
        return {min(l_min, x), max(r_max, x), s};

    }
};
// @lc code=end

