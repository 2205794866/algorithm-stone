/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    void Delete_Node(struct ListNode *p)
    {
        std::cout << "1" << std::endl;
        struct ListNode *q = p->next;
        p->next = q->next;
        delete q;
    }




    ListNode* deleteDuplicates(ListNode* head) {
        struct ListNode *p;
        p = head;
        if(!p)
        return p;
        while (p->next)
        {
            if(p->val == p->next->val)
            {
                Delete_Node(p);
            }
            else
            {
                p = p->next;
            }
        }
        return head;    
    }
};
// @lc code=end

