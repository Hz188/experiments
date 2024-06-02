/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    int maxAncestorDiff(TreeNode* root, int mx = 0, int mn = 1000001) {
        if(!root) return 0;

        mx = max(root->val, mx);
        mn = min(root->val, mn);
        int l = maxAncestorDiff(root->left, mx, mn);
        int r = maxAncestorDiff(root->right, mx, mn);
        int cur = max(abs(root->val - mx), abs(root->val - mn));

        return max(l, max(r, cur));
    }
};

// @lc code=end

