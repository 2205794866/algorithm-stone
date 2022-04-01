/*
 * @lc app=leetcode.cn id=1161 lang=cpp
 *
 * [1161] 最大层内元素和
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
    int maxLevelSum(TreeNode* root) {
        int max_sum, ans, index;
        max_sum = 0x80000000;
        index = 0;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            /* code */
            int n = Q.size();
            int sum = 0;
            index ++;
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
            if(sum > max_sum)
            {
                max_sum = sum;
                ans = index;
            }
        }
        return ans;
    }
};
// @lc code=end

