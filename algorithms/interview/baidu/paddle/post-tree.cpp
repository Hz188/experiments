#include <iostream>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    std::stack<TreeNode*> stack;
    TreeNode* lastVisited = nullptr;
    TreeNode* current = root;

    while (!stack.empty() || current != nullptr) {
        // 先遍历到最左子节点
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        // 获取栈顶节点
        current = stack.top();

        // 如果右子树为空或已经被访问过，访问当前节点
        if (current->right == nullptr || current->right == lastVisited) {
            std::cout << current->val << " ";  // 访问节点
            stack.pop();
            lastVisited = current;
            current = nullptr;  // 避免重复访问
        } else {
            // 如果右子树未访问过，转向右子树
            current = current->right;
        }
    }
}

int main() {
    // 创建一个二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Post-order Traversal: ";
    postOrderTraversal(root);
    std::cout << std::endl;

    // 释放内存
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
