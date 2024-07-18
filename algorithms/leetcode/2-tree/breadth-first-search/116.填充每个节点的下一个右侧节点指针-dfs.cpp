/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <vector>
using namespace std;
class Solution {
    vector<Node *> pre;
public:
    Node *connect(Node *root) {
        dfs(root, 0); // 根节点的深度为 0
        return root;
    }

    void dfs(Node *node, int depth) {
        if (node == nullptr) {
            return;
        }
        if (depth == pre.size()) { // node 是这一层最左边的节点
            pre.push_back(node);
        } else { // pre[depth] 是 node 左边的节点
            pre[depth]->next = node; // node 左边的节点指向 node
            pre[depth] = node;
        }
        dfs(node->left, depth + 1);
        dfs(node->right, depth + 1);
    }
};
// @lc code=end

