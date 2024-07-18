/*
 * @lc app=leetcode.cn id=2816 lang=cpp
 *
 * [2816] 翻倍以链表形式表示的数字
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
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head); 
        ListNode* dummy_head = new ListNode(-1, head);
        auto cur = dummy_head;
        int c = 0;
        while(cur->next) {
            int val = cur->next->val * 2 + c;
            cur->next->val = val % 10;
            c = val / 10;
            cur = cur->next;
        }
        if(c){
            cur->next = new ListNode(1); 
        }
        return reverse(head);
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

