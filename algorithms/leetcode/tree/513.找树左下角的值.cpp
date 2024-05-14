/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
#include <queue>
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {

        queue<TreeNode*> que{};
        que.emplace(root);
        int res{};
        while(!que.empty()){
            auto cur = que.front();
            res = cur->val;
            que.pop();
            if(cur->right) que.emplace(cur->right);
            if(cur->left) que.emplace(cur->left);
        }
        return res;
    }
};
// @lc code=end

