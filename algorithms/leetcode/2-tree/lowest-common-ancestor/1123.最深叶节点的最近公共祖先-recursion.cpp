/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
#include <utility>
using namespace std;
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }

    pair<int, TreeNode*> dfs(TreeNode *node) {
        if (node == nullptr)
            return {0, nullptr};
        auto [left_height, left_lca] = dfs(node->left);
        auto [right_height, right_lca] = dfs(node->right);
        if (left_height > right_height) // 左子树更高
            return {left_height + 1, left_lca};
        if (left_height < right_height) // 右子树更高
            return {right_height + 1, right_lca};
        return {left_height + 1, node}; // 一样高
    }
};
// @lc code=end

