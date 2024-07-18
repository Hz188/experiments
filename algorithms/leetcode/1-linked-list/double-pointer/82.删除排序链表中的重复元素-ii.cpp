/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy_head = new ListNode(-1, head);
        auto pre = dummy_head;
        auto cur = head;
        while(cur && cur->next) {
            int val = cur->val;
            if(cur->next->val == val) {
                while(cur && cur->val == val) {
                    cur = cur->next; // 这个时候cur->next值不是val了，相当于找到了一段等于val的区间
                    pre->next = cur;
                }
            } else {
                cur = cur->next;
                pre = pre->next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

