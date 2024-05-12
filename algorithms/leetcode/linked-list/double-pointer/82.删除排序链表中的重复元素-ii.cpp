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
        auto cur = dummy_head;
        while(cur->next && cur->next->next) {
            int val = cur->next->val;
            if(cur->next->next->val == val) {
                while(cur->next && cur->next->val == val) {
                    cur->next = cur->next->next; // 这个时候cur->next值不是val了，相当于找到了一段等于val的区间
                }
            } else {
                cur = cur->next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end

