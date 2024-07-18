/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
    // 记录所有子树以及出现的次数
    unordered_map<string, int> memo;
    // 记录重复的子树根节点
    vector<TreeNode*> res;

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }

        string left = traverse(root->left);
        string right = traverse(root->right);

        string subTree = left + "," + right + "," + to_string(root->val);

        int freq = memo[subTree];
        // 多次重复也只会被加入结果集一次
        if (freq == 1) {
            res.push_back(root);
        }
        // 给子树对应的出现次数加一
        memo[subTree] = freq + 1;
        return subTree;
    }
};
// @lc code=end

