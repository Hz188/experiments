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
    //前序:节点值往下传 -> 函数参数
    bool isValidBST(TreeNode *root) {
        if(!root) return true;
        return post_dfs(root).second != LONG_MAX;
    }

    // 后序遍历:节点值往上传 -> 返回值
    pair<long, long> post_dfs(TreeNode* root) {
        // 要向上返回当前子树的{min, max}值
        // 所以空节点让他返回{inf, -inf}之后
        // 向上递归，遇到一个具体节点的时候，min(val, inf) max(val, -inf) 一定是val，来保证逻辑正确
        if(!root) return {LONG_MAX,LONG_MIN}; 

        auto left = post_dfs(root->left);
        auto right = post_dfs(root->right);
        int x = root->val;
        if( x <= left.second || x >= right.first) {
            //不满足条件，返回{-inf, inf} 之后会层层如此返回，到最终函数调用结果
            return {LONG_MIN, LONG_MAX}; 
        }
        return {min(left.first, (long)x), max(right.second, (long)x)};
    }
};
// @lc code=end

