/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* res = nullptr;
        for(auto& l: lists){
            res = mergeTwoLists(res, l);
        }
        return res;

    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        while(p1 && p2) {
            if(p1->val < p2->val) {
                p->next = p1;
                p = p->next;
                p1 = p1->next;
            } else {
                p->next = p2;
                p = p->next;
                p2 = p2->next;
            }
        }
        if(p1)
            p->next = p1;
        else
            p->next = p2;

        return dummy->next;

    }
};
// @lc code=end

