/*
 * @lc app=leetcode.cn id=1315 lang=cpp
 *
 * [1315] 祖父节点值为偶数的节点和
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
    int ans;

    void dfs(TreeNode *root, bool flag)
    {
        if(root == nullptr)
        return ;
        if(flag == true)
        {
            if(root->left != nullptr)
            ans += root->left->val;
            if(root->right != nullptr)
            ans += root->right->val;
        }
        flag = (root->val % 2 == 0) ? true : false;
        dfs(root->left, flag);
        dfs(root->right, flag);
        
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        ans = 0;
        dfs(root, false);
        return ans;
    }
};
// @lc code=end

