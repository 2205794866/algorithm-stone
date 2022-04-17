/*
 * @lc app=leetcode.cn id=655 lang=cpp
 *
 * [655] 输出二叉树
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
    int getHeight(TreeNode *root)
    {
        if(root == nullptr)
        return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }


    void fill(TreeNode *root, int left, int right, int now_height, vector<vector<string>> &ans)
    {
        if(root == nullptr)
        return;
        int mid = (left + right) / 2;
        ans[now_height][(left + right)/2] = to_string(root->val);
        fill(root->left, left, mid-1, now_height + 1, ans);
        fill(root->right, mid + 1, right, now_height + 1, ans);
    }




public:
    vector<vector<string>> printTree(TreeNode* root) {
        int height = getHeight(root);
        if(height == 0)
        return {{}};
        vector<vector<string>> ans(height, vector<string>(pow(2, height) - 1, ""));
        fill(root, 0, pow(2, height) - 1, 0, ans);
        return ans;
    }
};
// @lc code=end

