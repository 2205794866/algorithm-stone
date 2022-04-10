/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    // int ans;
    // vector<int> combine;
    // int get_sum()
    // {
    //     int sum = 0;
    //     for(auto n: combine)
    //     {
    //         sum *= 10;
    //         sum += n;
    //     }
    //     return sum;
    // }
    int sum = 0;

public:
    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
        return 0;
        sum *= 10;
        sum += root->val;
        if(root->left == nullptr && root->right == nullptr)
        {
            int t = sum;
            sum -= root->val;
            sum /= 10;
            return t;
        }
        int L = sumNumbers(root->left);
        int R = sumNumbers(root->right);
        sum -= root->val;
        sum /= 10;
        return L+R;
    }
};
// @lc code=end

