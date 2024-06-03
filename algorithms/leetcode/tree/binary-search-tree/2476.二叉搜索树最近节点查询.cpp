/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
#include <ranges>
using namespace std;
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        dfs(root);
        int n = arr.size();
        vector<vector<int>> ans{};
        for(int q: queries){
            int j = ranges::lower_bound(arr, q) - arr.begin();
            int mx = j < n ? arr[j]: -1;
            if(j == n || arr[j] != q) {
                j--;
            }
            int mn = j >= 0 ? arr[j]:-1;
            ans.push_back({mn, mx});
        }
        return ans;
    }

private:
    vector<int> arr{};
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        arr.push_back(root->val);
        dfs(root->right);
    }
};
// @lc code=end

