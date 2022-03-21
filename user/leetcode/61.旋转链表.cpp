/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || head == nullptr || head->next == nullptr)
    return head;
    int n = 1;
    ListNode *p = head;
    while(p->next!=nullptr)
    {
        p = p->next;
        n ++;
    }
    int add = n - k%n;
    if(add == n)
    {
        return head;
    }
    p->next = head;
    while(add--)
    {
        p = p->next;
    }
    ListNode *ret = p->next;
    p->next = nullptr;
    return ret;
        
    }
};
// @lc code=end

