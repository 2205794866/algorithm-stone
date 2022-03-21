/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一棵树的子树
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
using namespace std;

class Solution {
public:
    bool is_same(TreeNode *p, TreeNode *q)
    {
        if(p == nullptr && q == nullptr)
        return true;

        if(p == nullptr || q == nullptr)
        return false;

        if(p->val != q->val)
        return false;

        bool L = false;
        bool R = false;
        L = is_same(p->left, q->left);
        if(L == true)
        R = is_same(p->right, q->right);
        return R;
        
    }



    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(is_same(root, subRoot) == false)
        {
            if(root == nullptr)
                return false;
            if(isSubtree(root->left, subRoot) == false)
            {
                if(isSubtree(root->right, subRoot) == false)
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

