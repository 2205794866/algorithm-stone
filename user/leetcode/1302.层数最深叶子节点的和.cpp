/*
 * @lc app=leetcode.cn id=1302 lang=cpp
 *
 * [1302] 层数最深叶子节点的和
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
    int deepestLeavesSum(TreeNode* root) {
        int sum;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int n = Q.size();
            sum = 0;
            for(int i = 0; i<n; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                sum += p->val;
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
            }
        }
        return sum;
    }
};
// @lc code=end

