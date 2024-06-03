/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    //前序:节点值往下传 -> 函数参数
    bool isValidBST(TreeNode *root, long left = LONG_MIN, long right = LONG_MAX) {
        return post_dfs(root).second != LONG_MAX;
        if (root == nullptr)
            return true;
        long x = root->val;
        return left < x && x < right &&
                isValidBST(root->left, left, x) &&
                isValidBST(root->right, x, right);
    }
};
// @lc code=end

