/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *p, *q;
        q = head;
        while(q != nullptr)
        {
            if(q->val == val)
            {
                if(q == head)
                {
                    head = q->next;
                    q = head;
                }
                else
                {
                    q = q->next;
                    p->next = q;
                }
            }
            else
            {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
// @lc code=end

