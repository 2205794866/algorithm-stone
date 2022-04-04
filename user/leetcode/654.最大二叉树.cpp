/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode *build(vector<int> &nums, int left, int right)
    {
        if(left > right)
        return nullptr;
        int max_one = left, max_val = nums[left];
        for(int i = left + 1; i<=right; i++)
        {
            if(nums[i] > max_val)
            {
                max_val = nums[i];
                max_one = i;
            }
        }
        auto root = new TreeNode(max_val);
        root->left = build(nums, left, max_one-1);
        root->right = build(nums, max_one+1, right);
        return root;
    }


public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return build(nums, 0, n-1);
    }
};
// @lc code=end

