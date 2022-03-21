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
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
private:
    /*②: 递归
    ListNode *fontPointer;
    */

public:
    /*②: 递归
    bool recursivelyCheck(ListNode *currentNode)
    {
        if(currentNode != nullptr)
        {
            if(recursivelyCheck(currentNode->next) == false)
            return false;
            if(currentNode->val != fontPointer->val)
            return false;
            fontPointer = fontPointer->next;
        }
        return true;
    }
    */




    bool isPalindrome(ListNode* head) {
        /* ①: 数组存储后双指针
        ListNode *p = nullptr;
        vector<int> val;
        vector<int>::iterator p1, p2;
        p = head;
        while(p != nullptr)
        {
            val.push_back(p->val);
            p = p->next;
        }
        p1 = val.begin(), p2 = val.end() - 1;
        while(p1 <= p2)
        {
            if(*p1 != *p2)
            {
                return false;
            }
            p1 ++, p2--;
        }
        return true;
        */


       /*②: 递归
        fontPointer = head;
        return recursivelyCheck(head);
        */

    //    /*③: 快慢指针
        ListNode *fast, *slow;
        ListNode *pre,*prepre;
        if(head == nullptr || head->next == nullptr)
        return true;
        fast = slow = head;
        prepre = nullptr;
        while(fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
            pre->next = prepre;
            prepre = pre;
        }
        if(fast != nullptr)
        slow = slow->next;
        while(pre != nullptr && slow != nullptr)
        {
            if(pre->val != slow->val)
            return false;
            pre = pre->next;
            slow = slow->next;
        }
        return true;

    //    */
    }
};
// @lc code=end

