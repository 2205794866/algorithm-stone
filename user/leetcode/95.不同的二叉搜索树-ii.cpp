/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
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
    vector<TreeNode *> build(int start, int end)
    {
        if(start > end)
        return {nullptr};
        vector<TreeNode *> all_trees;
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode *> left_trees = build(start, i-1);
            vector<TreeNode *> right_trees = build(i+1, end);
            for(auto& left: left_trees)
            {
                for(auto& right:right_trees)
                {
                    TreeNode *cur = new TreeNode(i, left, right);
                    all_trees.emplace_back(cur);
                }
            }
        }
        return all_trees;
    }



public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
        return {};
        return build(1, n);
    }
};
// @lc code=end

