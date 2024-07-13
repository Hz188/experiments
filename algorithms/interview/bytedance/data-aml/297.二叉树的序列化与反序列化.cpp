/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Codec {
    string SEP;
    string NULL_NODE;

public:
    Codec() : SEP(","), NULL_NODE("#") {}

    // 主函数，将二叉树序列化为字符串
    string serialize(TreeNode* root) {
        stringstream ss;
        serialize(root, ss);
        return ss.str();
    }

    // 辅助函数，将二叉树存入 StringBuilder
    void serialize(TreeNode* root, stringstream& ss) {
        if (root == nullptr) {
            ss << NULL_NODE << SEP;
            return;
        }

        // *****前序遍历位置*****
        ss << root->val << SEP;
        // *********************

        serialize(root->left, ss);
        serialize(root->right, ss);
    }

    // 主函数，将字符串反序列化为二叉树结构
    TreeNode* deserialize(string data) {
        // 将字符串转化成列表
        list<string> nodes;
        stringstream ss(data);
        string item;
        while (getline(ss, item, ',')) {
            nodes.push_back(item);
        }
        return deserialize(nodes);
    }

    // 辅助函数，通过 nodes 列表构造二叉树
    TreeNode* deserialize(list<string>& nodes) {
        if (nodes.empty()) return nullptr;

        // *****前序遍历位置*****
        // 列表最左侧就是根节点
        string first = nodes.front();
        nodes.pop_front();
        if (first == NULL_NODE) return nullptr;
        TreeNode* root = new TreeNode(stoi(first));
        // *********************

        root->left = deserialize(nodes);
        root->right = deserialize(nodes);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

