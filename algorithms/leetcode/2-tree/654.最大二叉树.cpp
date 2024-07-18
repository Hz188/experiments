/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
#include <climits>
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }
    
    TreeNode* build(vector<int>& nums, int lo, int hi) {
        if(lo > hi) {
            return nullptr;
        }

        // 找到数组中的最大值和对应的索引
        int index = -1, maxVal = INT_MIN;
        for (int i = lo; i <= hi; i++) {
            if (maxVal < nums[i]) {
                index = i;
                maxVal = nums[i];
            }
        }

        TreeNode* root = new TreeNode(maxVal);
        // 递归调用构造左右子树
        root->left = build(nums, lo, index - 1);
        root->right = build(nums, index + 1, hi);

        return root;
    }
};
// @lc code=end

