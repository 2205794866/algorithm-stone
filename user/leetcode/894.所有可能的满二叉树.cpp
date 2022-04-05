/*
 * @lc app=leetcode.cn id=894 lang=cpp
 *
 * [894] 所有可能的满二叉树
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
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> dp;
        if(n & 1 == 0)  return dp;
        if(n == 1)
        {
            dp.push_back(new TreeNode(0));
            return dp;
        }
        for(int i = 1; i<=n-2; i+=2)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right= allPossibleFBT(n-1-i);
            for(int j = 0; j<left.size(); j++)
            {
                for(int k = 0; k<right.size(); k++)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    dp.push_back(root);
                }
            }
        }
        return dp;
    }
};
// @lc code=end

