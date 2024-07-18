/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
#include <climits>
#include <utility>
using namespace std;

class Solution {
public:
    // 中序遍历:判断严格递增
    int pre = INT_MIN;
    bool isValidBST(TreeNode *root) {
        if (root == nullptr)
            return true;
        if(!isValidBST(root->left))
            return false;
        if(root->val <= pre) {
            return false;
        }
        pre = root->val;
        return isValidBST(root->right);
    }
    //第二种写法
    /*
    TreeNode* pre{nullptr};
    bool valid{true};
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        if(!pre) {
            pre = root;
        } else {
            if (pre->val >= root->val) {
                valid = false;
                return;
            }
            pre = root;
        }
        dfs(root->right);
        // call dfs(root), then return valid;
    }
    */
};
// @lc code=end

