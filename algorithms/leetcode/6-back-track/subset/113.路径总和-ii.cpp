/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<int> path{};
    vector<vector<int>> ans{};
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return {};
        dfs(root, targetSum);
        return ans;
    }

    void dfs(TreeNode* root, int target) {
        if(!root) return;
        path.push_back(root->val);
        target -= root->val;

        if(root->left == root->right && target == 0) {
            ans.push_back(path);
        }

        if(root->left) dfs(root->left, target);
        if(root->right) dfs(root->right, target);
        path.pop_back();
    }

};
// @lc code=end

