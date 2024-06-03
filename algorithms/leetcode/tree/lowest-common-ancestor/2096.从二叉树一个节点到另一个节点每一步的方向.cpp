/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] 从二叉树一个节点到另一个节点每一步的方向
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
#include <string>
using namespace std;
class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue, string d = "") {
        string path1, path2;
        dfs(root, startValue, path1);
        dfs(root, destValue, path2);

        while (!path1.empty() && !path2.empty() && path1[0] == path2[0]) {
            path1.erase(path1.begin());
            path2.erase(path2.begin());
        }

        string result(path1.size(), 'U');
        for (char c : path2) {
            result += c;
        }
        return result;
    }
private:
    bool dfs(TreeNode* node, int target, string& path) {
        if(!node) return false;
        if(node->val == target) return true;
        path.push_back('L');
        if(dfs(node->left, target, path)) {
            return true;
        }
        path.pop_back();;
        path.push_back('R');
        if(dfs(node->right, target, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }
};
// @lc code=end

