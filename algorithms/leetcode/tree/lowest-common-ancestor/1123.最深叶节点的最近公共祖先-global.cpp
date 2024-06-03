/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    TreeNode* ans{nullptr};
    int max_depth{-1};
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root, int level = 0) {
        dfs(root, 0);
        return ans;
    }

    int dfs(TreeNode* root, int depth) {
        if(!root) {
            max_depth = max(max_depth, depth);
            return depth;
        }
        int left_depth = dfs(root->left, depth+1);
        int right_depth = dfs(root->right, depth+1);
        if(left_depth == right_depth && left_depth == max_depth) {
            ans = root;
        }
        return max(left_depth, right_depth);
    }
};
// @lc code=end

