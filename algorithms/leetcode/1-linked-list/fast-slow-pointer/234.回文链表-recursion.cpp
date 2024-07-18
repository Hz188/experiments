/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        auto slow = head;
        auto fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // even: [1,2,3,4] slow = 3
        // odd: [1,2,3,4,5] slow = 3
        if(fast) {
            slow = slow->next;
        }
        // even: [1,2,3,4] slow = 3
        // odd: [1,2,3,4,5] slow = 4
        ListNode* pre{nullptr};
        auto cur = slow;
        while(cur) {
            auto nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        while(pre) {
            if(head->val != pre->val) {
                return false;
            }
            head = head->next;
            pre = pre->next;
        }
        return true;

    }
};
// @lc code=end

