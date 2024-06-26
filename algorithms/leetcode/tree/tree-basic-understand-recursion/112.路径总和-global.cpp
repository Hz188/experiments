// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem112.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(!root) return false;
        dfs(root, targetSum);
        return ans;
    }
private:
    bool ans {false};
    void dfs(TreeNode* root, int targetSum) {
        if(!root) return;
        if(!root->left && !root->right && root->val == targetSum) {
            ans = true;
            return;
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);

    }
};
// @lc code=end

