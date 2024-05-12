// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem143.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
class Solution {
public:
    void reorderList(ListNode* head) {
        auto slow = head;
        auto fast = head;
        while(fast && fast->next) { 
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* pre{nullptr};
        while(slow) {
            auto next = slow->next;
            slow->next = pre;
            pre = slow;
            slow = next;
        }
        while(pre->next) {
            auto next = head->next;
            auto next_2 = pre->next;
            head->next = pre;
            pre->next = next;
            head = next;
            pre = next_2;
        }
    }
};
// @lc code=end

