/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] 二叉树的完全性检验
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
    bool isCompleteTree(TreeNode* root) {
        if(root == nullptr)
        return true;
        queue<TreeNode *> Q;
        bool flag = false;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode *p = Q.front();
            Q.pop();
            if(p == nullptr)
            {
                flag = true;
                continue;
            }
            if(flag == true)
            return false;
            Q.push(p->left);
            Q.push(p->right);
        }
        return true;
    }
};
// @lc code=end

