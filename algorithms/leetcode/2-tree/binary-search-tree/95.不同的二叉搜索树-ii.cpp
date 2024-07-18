/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
using namespace std;

class Solution {
public:
    // 主函数
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        // 构造闭区间 [1, n] 组成的 BST
        return build(1, n);
    }

private:
    // 构造闭区间 [lo, hi] 组成的 BST
    vector<TreeNode*> build(int lo, int hi) {
        vector<TreeNode*> res;
        // base case
        if (lo > hi) {
            res.push_back(nullptr);
            return res;
        }

        // 1、穷举 root 节点的所有可能。
        for (int i = lo; i <= hi; i++) {
            // 2、递归构造出左右子树的所有合法 BST。
            vector<TreeNode*> leftTree = build(lo, i - 1);
            vector<TreeNode*> rightTree = build(i + 1, hi);
            // 3、给 root 节点穷举所有左右子树的组合。
            for (TreeNode* left : leftTree) {
                for (TreeNode* right : rightTree) {
                    // i 作为根节点 root 的值
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end

