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
        front_pointer = head;
        return help(head);
    }
private:
    ListNode* front_pointer;
    bool help(ListNode* node) {
        if(node) {
            //1. help(node->next) = true
            //  下一个node=nullptr，那么当前node不用返回，可以开始比较
            //  or
            //  下一个node正常的判断完毕了，没返回false，接着判断下一个节点了
            //2. help(node->next) = false
            //  下一个节点返回了false，意思是已经出现了错误的情况，这里不用再比较了，已经错了
            if(!help(node->next)) return false; 
            
            if(node->val != front_pointer->val) return false;

            front_pointer = front_pointer->next;
        }

        return true; // node不存在
    }
};
// @lc code=end

