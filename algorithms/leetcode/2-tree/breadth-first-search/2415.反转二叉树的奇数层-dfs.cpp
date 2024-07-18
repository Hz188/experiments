/*
 * @lc app=leetcode.cn id=2415 lang=cpp
 *
 * [2415] 反转二叉树的奇数层
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
#include <vector>
#include <utility>
using namespace std;
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        dfs(root->left, root->right, true);
        return root;
    }

    void dfs(TreeNode* node1, TreeNode* node2, bool is_odd) {
        if(!node1 || !node2) return;
        if(is_odd) {
            // swap(node1->left, node2->right);
            // swap(node1->right, node2->left);
            swap(node1->val, node2->val);
        }
        dfs(node1->left, node2->right, !is_odd);
        dfs(node1->right, node2->left, !is_odd);
    }
};
// @lc code=end

