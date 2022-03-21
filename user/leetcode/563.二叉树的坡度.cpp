/*
 * @lc app=leetcode.cn id=563 lang=cpp
 *
 * [563] 二叉树的坡度
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
using namespace std;
class Solution {
    int get_Tilt(TreeNode *root, int &ans)
    {
        if(root == nullptr)
        return 0;
        int L = get_Tilt(root->left, ans);
        int R = get_Tilt(root->right, ans);
        ans += (int)abs(L-R);
        return L+R + root->val;
    }



public:
    int findTilt(TreeNode* root) {
        int ans = 0;
        get_Tilt(root, ans);
        return ans;
    }
};
// @lc code=end

