/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for(int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return build(preorder, 0, n-1, inorder, 0, n-1);
    }
private:

    unordered_map<int, int> index{};
    TreeNode* build(vector<int>& preorder, int p_start, int p_end, 
                    vector<int>& inorder, int i_start, int i_end) {
        if(p_start > p_end) return nullptr;
        int root_val = preorder[p_start];
        int root_idx = index[root_val];
        int left_size = root_idx - i_start;
        // [root, [left...], [right...]]
        // [p_start, [p_start+1, p_start+left_size], [p_start+left_size+1, p_end]]
        // [[left...], root, [right...]]
        // [[i_start, idx-1],idx,[idx+1, i_end]]
        TreeNode* root = new TreeNode(root_val);
        root->left = build(preorder, p_start+1, p_start+left_size, inorder, i_start, root_idx-1);
        root->right = build(preorder, p_start+left_size+1, p_end, inorder, root_idx+1, i_end);
        return root;
    }
};
// @lc code=end

