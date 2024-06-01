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
        if(!head) return nullptr;
        //[a, b)  翻转k个
        ListNode *a, *b;
        a = b = head;
        for(int i = 0; i < k; i++) {
            if(!b) return head; // 不够k个
            b = b->next;
        }
        ListNode* newHead = reverse(a, b);
        a->next = reverseKGroup(b, k);
        return newHead;

    }

    ListNode* reverse(ListNode* a, ListNode* b) {
        ListNode* pre, *cur, *nxt;
        cur = a;
        pre = nullptr;
        while(cur != b) {
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};
// @lc code=end

