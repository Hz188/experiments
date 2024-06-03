/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
#include <unordered_map>
using namespace std;
class Solution {
    unordered_map<int, int> index;

public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for (int i = 0; i < postorder.size(); i++) {
            index[postorder[i]] = i;
        }
        return build(preorder, 0, preorder.size() - 1,
                    postorder, 0, postorder.size() - 1);
    }

    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end,
                    vector<int>& postorder, int post_start, int post_end) {
        if (pre_start > pre_end) {
            return nullptr;
        }
        if (pre_start == pre_end) {
            return new TreeNode(preorder[pre_start]);
        }

        int root_val = preorder[pre_start];
        int left_root_val = preorder[pre_start + 1];
        int left_root_idx = index[left_root_val];
        int left_size = left_root_idx - post_start + 1;

        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, pre_start + 1, pre_start + left_size,
                            postorder, post_start, left_root_idx);
        root->right = build(preorder, pre_start + left_size + 1, pre_end,
                            postorder, left_root_idx + 1, post_end - 1);
        return root;
    }
};
// @lc code=end

