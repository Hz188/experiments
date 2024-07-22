/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len = 0;
        auto p = head;
        while(p) {
            len++;
            p = p->next;
        }
        k = k % len;
        p = head;
        for(int i = 0; i < k; i++) {
            p = p->next;
        }
        auto q = head;
        while(p->next) {
            q = q->next;
            p = p->next;
        }
        p->next = head;
        auto new_head = q->next;
        q->next = nullptr;
        return new_head;
    }
};
// @lc code=end

