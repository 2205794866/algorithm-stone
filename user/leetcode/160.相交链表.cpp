/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // vector<ListNode *> ListA;
        // vector<ListNode *> ListB;
        // ListNode *p;
        // vector<ListNode *>:: iterator p1, p2;
        // for(p = headA; p!=nullptr; p = p->next)
        // ListA.push_back(p);
        // for(p = headB; p!=nullptr; p = p->next)
        // ListB.push_back(p);
        // p1 = ListA.end() - 1;
        // p2 = ListB.end() - 1;
        // p = nullptr;
        // while(p1 >= ListA.begin() && p2 >= ListB.begin() && *p1 == *p2 )
        // {
        //     p = *p1;
        //     p1--;
        //     p2--;
        // }
        // return p;
        ListNode *p1, *p2;
        p1 = headA, p2 = headB;
        if(!p1 || !p2)
        return nullptr;
        while(p1 != p2)
        {
            p1 = p1==nullptr ? headB : p1->next;
            p2 = p2==nullptr ? headA : p2->next;
        }
        return p1;
    }
};
// @lc code=end

