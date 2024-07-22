/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <functional>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> ans{};
        function<void(TreeNode*, string)> dfs = [&](TreeNode* root, string path) {
            path += to_string(root->val);
            if(root->left == root->right){
                ans.push_back(path);
                return;
            }
            if(root->left) dfs(root->left, path + "->");
            if(root->right) dfs(root->right, path + "->");
        };
        dfs(root, "");
        return ans;


    }

};
// @lc code=end

