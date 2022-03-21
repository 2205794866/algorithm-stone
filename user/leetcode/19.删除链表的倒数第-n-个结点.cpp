/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // vector<ListNode *> nodelist;
        // ListNode *p = head, *q;
        // while(p != nullptr)
        // {
        //     nodelist.push_back(p);
        //     p = p->next;
        // }
        // int x = nodelist.size() - n;
        // if(x == 0)
        // return head->next;
        // p = nodelist[x];
        // q = nodelist[x - 1];
        // q->next = p->next;
        // return head;

        ListNode *dummy = new ListNode(0, head);
        ListNode *first = head;
        ListNode *second = dummy;
        for(int i = 0; i<n; i++)
        first = first->next;
        while(first != nullptr)
        {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode *ans = dummy->next;
        delete(dummy);
        return ans;

    }
};
// @lc code=end

