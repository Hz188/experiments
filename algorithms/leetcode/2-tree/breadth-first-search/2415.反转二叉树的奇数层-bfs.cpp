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
using namespace std;
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        vector<TreeNode*> q = {root};
        int level = 1;
        while (!q.empty()) {
            vector<TreeNode*> nxt;
            for (int i = 0; i < q.size(); i++) {
                TreeNode *node = q[i];
                if (node->left) {
                    nxt.push_back(node->left);
                }
                if (node->right) {
                    nxt.push_back(node->right);
                }
            }
            q = move(nxt);
            if(level){
                int l = 0, r = q.size()-1;
                while(l < r) {
                    auto node1 = q[l];
                    auto node2 = q[r];
                    swap(node1->val, node2->val);
                    l++, r--;
                }
            }
            level ^= 1;
        }
        return root;
    }
};
// @lc code=end

