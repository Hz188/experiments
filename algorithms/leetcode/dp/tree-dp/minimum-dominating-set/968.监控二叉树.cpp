/*
 * @lc app=leetcode.cn id=968 lang=cpp
 *
 * [968] 监控二叉树
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
    tuple<int, int, int> dfs(TreeNode *node) {
        if (!node) {
            return {INT_MAX / 2, 0, 0}; // 除 2 防止加法溢出
        }
        auto [l_choose, l_by_fa, l_by_children] = dfs(node->left);
        auto [r_choose, r_by_fa, r_by_children] = dfs(node->right);
        int choose = min(l_choose, l_by_fa) + min(r_choose, r_by_fa) + 1;
        int by_fa = min(l_choose, l_by_children) + min(r_choose, r_by_children);
        int by_children = min({l_choose + r_by_children, l_by_children + r_choose, l_choose + r_choose});
        return {choose, by_fa, by_children};
    }

public:
    int minCameraCover(TreeNode *root) {
        auto [choose, _, by_children] = dfs(root);
        return min(choose, by_children);
    }
};
// @lc code=end

