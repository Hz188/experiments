/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        auto p0 = head;
        while(p0) {
            len++;
            p0 = p0->next;
        }
        ListNode* dummy_head = new ListNode(-1, head);
        p0 = dummy_head;
        ListNode* pre{nullptr};
        auto cur = p0->next;
        while(len >= k) {
            len -= k;
            for(int i = 0; i < k; i++) {
                auto next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            auto p0_next = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = p0_next;
        }
        return dummy_head->next; 
    }
};
// @lc code=end

