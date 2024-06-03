/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <queue>
#include <deque>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res {};
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> que{};
        que.emplace(root);
        bool flag{true};
        while(!que.empty()){
            deque<int> level{};
            int sz = que.size();
            for (int i = 0; i < sz; i++){
                auto cur = que.front();
                if(flag) {
                    level.push_back(cur->val);
                } else {
                    level.push_front(cur->val);
                }
                que.pop();
                if(cur->left) que.emplace(cur->left);
                if(cur->right) que.emplace(cur->right);
            }
            res.emplace_back(level.begin(), level.end());
            flag = !flag;
        }
        return res;
    }
};
// @lc code=end

