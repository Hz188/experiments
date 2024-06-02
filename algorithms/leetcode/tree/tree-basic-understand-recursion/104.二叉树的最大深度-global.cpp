/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        dfs(root, 0);
        return ans;
    }

private:
    //use global variable to record the answer
    int ans = 0;
    void dfs(TreeNode* root, int cnt) {
        if(!root) return;
        cnt += 1;
        ans = max(cnt, ans);
        dfs(root->left, cnt);
        dfs(root->right, cnt);
        // call:  dfs(root, 0);
    }
};
// @lc code=end

