// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem445.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverse(l1);
        l2 = reverse(l2);
        auto l3 = addTwo(l1, l2);
        return reverse(l3);
    }
private:
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        auto new_head = reverse(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    // l1 和 l2 为当前遍历的节点，carry 为进位
    ListNode *addTwo(ListNode *l1, ListNode *l2, int carry = 0) {
        if (l1 == nullptr && l2 == nullptr) // 递归边界：l1 和 l2 都是空节点
            return carry ? new ListNode(carry) : nullptr; // 如果进位了，就额外创建一个节点
        if (l1 == nullptr) // 如果 l1 是空的，那么此时 l2 一定不是空节点
            swap(l1, l2); // 交换 l1 与 l2，保证 l1 非空，从而简化代码
        carry += l1->val + (l2 ? l2->val : 0); // 节点值和进位加在一起
        l1->val = carry % 10; // 每个节点保存一个数位
        l1->next = addTwo(l1->next, (l2 ? l2->next : nullptr), carry / 10); // 进位
        return l1;
    }

};
// @lc code=end

