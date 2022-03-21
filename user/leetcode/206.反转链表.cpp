/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * https://leetcode-cn.com/problems/reverse-linked-list/description/
 *
 * algorithms
 * Easy (72.45%)
 * Likes:    2166
 * Dislikes: 0
 * Total Accepted:    805.4K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：head = [1,2,3,4,5]
 * 输出：[5,4,3,2,1]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：head = [1,2]
 * 输出：[2,1]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：head = []
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 链表中节点的数目范围是 [0, 5000]
 * -5000 
 * 
 * 
 * 
 * 
 * 进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
 * 
 * 
 * 
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
/* 递归方法
    ListNode* get_reversed(ListNode *head, ListNode *prior)
   {
        if(head == nullptr)
        return prior;
        ListNode *new_head = get_reversed(head->next, head);
        head->next = prior;
        return new_head;
    }
*/

    ListNode* reverseList(ListNode* head) {
    /* 递归方法
        head = get_reversed(head, nullptr);
        return head;
    */
    // /*迭代方法
        ListNode *p ,*q, *r;
        p = nullptr;
        q = head;
        while(q != nullptr)
        {
            r = q->next;
            q->next = p;
            p = q;
            q = r;
        }
        head = p;
        return head;
    }
};
// @lc code=end

