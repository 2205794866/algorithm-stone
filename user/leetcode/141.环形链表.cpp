/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // bool hasCycle(ListNode *head) {
        // unordered_set<ListNode *> set;
        // ListNode *p = head;
        // while(p != nullptr)
        // {
        //     if(set.count(p))
        //     return true;
        //     set.insert(p);
        //     p = p->next;
        // }
        // return false;



        ListNode *fast, *slow;
        if(head == nullptr || head->next == nullptr)
        return false;
        fast = head->next, slow = head;
        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
            return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
    
};
// @lc code=end

