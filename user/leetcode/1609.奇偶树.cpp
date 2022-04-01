/*
 * @lc app=leetcode.cn id=1609 lang=cpp
 *
 * [1609] 奇偶树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        int index;
        queue<TreeNode *> Q;
        Q.push(root);
        index = 1;
        while(!Q.empty())
        {
            int n = Q.size();
            TreeNode *p = Q.front();
            int pre = p->val;
            Q.pop();
            if(p->left != nullptr)
            Q.push(p->left);
            if(p->right != nullptr)
            Q.push(p->right);
            if( (pre%2) ^ (index %2))
            return false;
            for(int i = 1; i<n; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                if(index % 2 == 1 && pre >= p->val)
                return false;
                if(index % 2 == 0 && pre <= p->val)
                return false;
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
                pre = p->val;
                if( (pre%2) ^ (index %2))
                return false;
            }
            index ++;
        }
        return true;
    }
};
// @lc code=end

