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
        ListNode* head = new ListNode(-1);
        ListNode* cur = head;
        int c = 0;
        while(l1 && l2) {
            c += l1->val + l2->val;
            auto node = new ListNode(c % 10);
            cur->next = node;
            c /= 10; 
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        while(l1) {
            int val = l1->val + c;
            cur->next = new ListNode(val % 10);
            c = val / 10;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2) {
            int val = l2->val + c;
            cur->next = new ListNode(val % 10);
            c = val / 10;
            l2 = l2->next;
            cur = cur->next;
        }
        if(c) {
            cur->next = new ListNode(1, nullptr);
        }
        return reverse(head->next);
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

};
// @lc code=end

