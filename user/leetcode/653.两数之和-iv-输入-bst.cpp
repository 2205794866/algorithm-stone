/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
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
    bool dfs(TreeNode *root, int target, unordered_set<int> &st)
    {
        if(root == nullptr)
        return false;
        if(st.count(target-root->val) == 1)
        return true;
        st.insert(root->val);
        return dfs(root->left, target, st) || dfs(root->right, target, st);
    }



public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return dfs(root, k, st);
    }
};
// @lc code=end

