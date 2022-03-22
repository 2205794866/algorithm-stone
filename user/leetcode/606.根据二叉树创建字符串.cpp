/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
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
    void get_str(TreeNode* root, string &ans)
    {
        if(root == nullptr)
        return;
        ans += to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        return ;
        ans.push_back('(');
        get_str(root->left, ans);
        ans.push_back(')');
        if(root->right != nullptr)
        {
            ans.push_back('(');
            get_str(root->right, ans);
            ans.push_back(')');
        }
        return ;
    }



public:
    string tree2str(TreeNode* root) {
        string ans = "";
        get_str(root, ans);
        return ans;
    }
};
// @lc code=end

