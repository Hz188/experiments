/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
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
#include <deque>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q{};
        q.emplace(root);
        deque<vector<int>> ans{};
        while(!q.empty()) {
            int sz = q.size();
            vector<int> level{};
            for(int i = 0; i < sz; ++i) {
                auto cur = q.front();
                level.push_back(cur->val);
                q.pop();
                if(cur->left) q.emplace(cur->left);
                if(cur->right) q.emplace(cur->right);
            }
            ans.emplace_front(level);
        }
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
// @lc code=end

