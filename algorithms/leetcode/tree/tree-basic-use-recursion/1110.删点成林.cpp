/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
#include <unordered_set>
using namespace std;
class Solution {
    vector<TreeNode*> ans;
    unordered_set<int> s;

    TreeNode* dfs(TreeNode* root) {
        if(!root) return nullptr;
        root->left = dfs(root->left);
        root->right = dfs(root->right);
        if(!s.count(root->val))
            return root;
        if(root->left) ans.push_back(root->left);
        if(root->right) ans.push_back(root->right);
        return nullptr;

    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int x: to_delete) {
            s.insert(x);
        }
        if(dfs(root)) ans.push_back(root);
        return ans;
    }

};
// @lc code=end

