/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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
#include <map>
#include <ranges>
using namespace std;
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> ans{};
        for(auto& [_, g]: groups) {
            ranges::sort(g);
            vector<int> vals{};
            for(auto& [_, val]: g) {
                vals.push_back(val);
            }
            ans.push_back(vals);
        }
        return ans;
    }
private:
    map<int, vector<pair<int, int>>> groups{};
    void dfs(TreeNode* root, int row, int col) {
        if(!root) return;
        groups[col].emplace_back(row, root->val);
        dfs(root->left, row+1, col-1);
        dfs(root->right, row+1, col+1);
    }

};
// @lc code=end

