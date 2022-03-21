/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // ListNode *slow, *fast;
        // ListNode *dummy = new ListNode(0, nullptr);
        // ListNode *tail = dummy;
        // slow = head;
        // fast = head;
        // while(fast != nullptr)
        // {
        //     if(fast->next == nullptr || fast->next->val != slow->val)
        //     {
        //         if(fast == slow)
        //         {
        //             tail->next = fast;
        //             tail = fast;
        //             fast = fast->next;
        //             slow = fast;
        //         }
        //         else
        //         {
        //             fast = fast->next;
        //             slow = fast;
        //         }
        //     }
        //     else
        //     {
        //         fast = fast->next;
        //     }    
        // }
        // tail->next = nullptr;
        // return dummy->next;
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = dummy;
        while (cur->next && cur->next->next)
        {
            /* code */
            if(cur->next->val == cur->next->next->val)
            {
                int x = cur->next->val;
                while(cur->next && cur ->next->val == x)
                {
                    cur->next = cur->next->next;
                }
            }
            else
            {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end

