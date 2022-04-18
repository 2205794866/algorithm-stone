/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int ans;
    int dfs(TreeNode *root)
    {
        if(root == nullptr)
        return 0;
        // int L = dfs(root->left);
        // int R = dfs(root->right);
        // ans = max(ans, max(L+root->val, max(R+root->val, max(L+R+root->val, root->val))));
        int L = max(dfs(root->left), 0);
        int R = max(dfs(root->right), 0);
        ans = max(ans, root->val + L + R);
        return max(root->val+L, root->val+R);
    }


public:
    int maxPathSum(TreeNode* root) {
        ans = 0x80000000;
        dfs(root);
        return ans;
    }
};
// @lc code=end

