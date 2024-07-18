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
class Solution {
public:
    Node *connect(Node *root) {
        Node *dummy = new Node();
        Node *cur = root;
        while (cur) {
            dummy->next = nullptr;
            Node *nxt = dummy; // 下一层的链表
            while (cur) { // 遍历当前层的链表
                if (cur->left) {
                    nxt->next = cur->left; // 下一层的相邻节点连起来
                    nxt = cur->left;
                }
                if (cur->right) {
                    nxt->next = cur->right; // 下一层的相邻节点连起来
                    nxt = cur->right;
                }
                cur = cur->next; // 当前层链表的下一个节点
            }
            cur = dummy->next; // 下一层链表的头节点
        }
        delete dummy;
        return root;
    }
};
// @lc code=end

