/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int num;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            num = Q.size();
            double sum = 0.0;
            for(int i = 0; i<num; i++)
            {
                TreeNode *temp = Q.front();
                Q.pop();
                sum += (double) temp->val;
                if(temp->left != nullptr)
                Q.push(temp->left);
                if(temp->right != nullptr)
                Q.push(temp->right);
            }
            ans.push_back(sum/num);
        }
        return ans;
    }
};
// @lc code=end

