/*
 * @lc app=leetcode.cn id=2641 lang=cpp
 *
 * [2641] 二叉树的堂兄弟节点 II
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
    TreeNode *replaceValueInTree(TreeNode *root) {
        root->val = 0;
        vector<TreeNode*> q = {root};
        while (!q.empty()) {
            vector<TreeNode*> nxt;
            // 计算下一层的节点值之和
            int next_level_sum = 0;
            for (auto node : q) {
                if (node->left) {
                    nxt.push_back(node->left);
                    next_level_sum += node->left->val;
                }
                if (node->right) {
                    nxt.push_back(node->right);
                    next_level_sum += node->right->val;
                }
            }

            // 再次遍历，更新下一层的节点值
            for (auto node : q) {
                int children_sum = (node->left ? node->left->val : 0) +
                                    (node->right ? node->right->val : 0);
                if (node->left) node->left->val = next_level_sum - children_sum;
                if (node->right) node->right->val = next_level_sum - children_sum;
            }
            q = move(nxt);
        }
        return root;
    }
};
// @lc code=end

