/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q{};
        q.emplace(root);
        vector<int> res{};
        while(!q.empty()) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                auto cur = q.front();
                if(i == n-1) res.push_back(cur->val);
                q.pop();
                if(cur->left){
                    q.emplace(cur->left);
                }
                if(cur->right){
                    q.emplace(cur->right);
                }
            }
        }
        return res;
    }
    // 递归解法
    vector<int> ans{};
    void dfs(TreeNode* root, int depth) {
        if(!root) return;
        if (depth == ans.size()) {
            ans.push_back(root->val);
        }
        dfs(root->right, depth+1);
        dfs(root->left, depth+1);
        // call: dfs(root, 0);
    }
};
// @lc code=end

