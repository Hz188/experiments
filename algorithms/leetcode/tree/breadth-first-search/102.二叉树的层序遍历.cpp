/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res {};
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> que{};
        que.emplace(root);
        while(!que.empty()){
            vector<int> level{};
            int sz = que.size();
            for (int i = 0; i < sz; i++){
                auto cur = que.front();
                level.push_back(cur->val);
                que.pop();
                if(cur->left) que.emplace(cur->left);
                if(cur->right) que.emplace(cur->right);
            }
            res.push_back(level);
        }
        return res;

    }
};
// @lc code=end

