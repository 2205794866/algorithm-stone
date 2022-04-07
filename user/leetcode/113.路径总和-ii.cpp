/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> ans;
    vector<int> combine;

    void dfs(TreeNode *root,int targetSum)
    {
        if(root == nullptr)
        {
            return;
        }
        targetSum -= root->val;
        combine.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr && targetSum == 0)
        {
            ans.push_back(combine);
            combine.pop_back();
            return;
        }
        dfs(root->left, targetSum);
        dfs(root->right, targetSum);
        combine.pop_back();
        return;
    }


public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};
// @lc code=end

