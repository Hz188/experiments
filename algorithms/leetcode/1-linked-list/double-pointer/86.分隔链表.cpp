/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* d1 = new ListNode(-1);
        ListNode* d2 = new ListNode(-1);
        ListNode* lower = d1;
        ListNode* greater = d2;
        ListNode* p = head;
        while(p) {
            if(p->val < x) {
                lower->next = p;
                p = p->next;
                lower = lower->next;
                lower->next = nullptr;
            } else {
                greater->next = p;
                p = p->next;
                greater = greater->next;
                greater->next = nullptr;
            }
        }
        lower->next = d2->next;
        return d1->next;
    }
};
// @lc code=end

