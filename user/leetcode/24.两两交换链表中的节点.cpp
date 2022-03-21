/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    void Exchange(ListNode *ahead)
    {
        ListNode *first = ahead->next;
        if(first == nullptr || first->next == nullptr)
        return ;
        ahead->next = first->next;
        first->next = first->next->next;
        ahead->next->next = first;
        Exchange(first);
    }




    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0, head);
        Exchange(dummy);
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
// @lc code=end

