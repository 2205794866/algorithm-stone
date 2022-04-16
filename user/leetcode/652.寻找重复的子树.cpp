/*
 * @lc app=leetcode.cn id=652 lang=cpp
 *
 * [652] 寻找重复的子树
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
    string dfs(TreeNode *root, vector<TreeNode *> &ans, unordered_map<string, int> &mp)
    {
        if(root == nullptr)
        return "";
        string str = to_string(root->val) + "," + dfs(root->left, ans, mp) + "," + dfs(root->right, ans, mp);
        mp[str] ++;
        if(mp[str] == 2)
        ans.push_back(root);
        return str;
    }


public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode *> ans;
        unordered_map<string, int> mp;
        dfs(root, ans, mp);
        return ans;
    }
};
// @lc code=end

