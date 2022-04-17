/*
 * @lc app=leetcode.cn id=863 lang=cpp
 *
 * [863] 二叉树中所有距离为 K 的结点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> ans;
    unordered_map<int, TreeNode *> mp;
    void find_parent(TreeNode *root)
    {
        if(root->left != nullptr)
        {
            mp[root->left->val] = root;
            find_parent(root->left);
        }
        if(root->right != nullptr)
        {
            mp[root->right->val] = root;
            find_parent(root->right);
        }
    }

    void find_ans(TreeNode *root, TreeNode *from, int depth, int k)
    {
        if(root == nullptr)
        return;
        if(depth == k)
        {
            ans.push_back(root->val);
            return;
        }
        if(root->left != from)
        find_ans(root->left, root, depth+1, k);
        if(root->right != from)
        find_ans(root->right, root, depth+1, k);
        if(mp[root->val] != from)
        find_ans(mp[root->val], root, depth+1, k);
    }



public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find_parent(root);
        find_ans(target, nullptr, 0, k);
        return ans;
    }
};
// @lc code=end

