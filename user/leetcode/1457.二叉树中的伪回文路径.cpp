/*
 * @lc app=leetcode.cn id=1457 lang=cpp
 *
 * [1457] 二叉树中的伪回文路径
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


    void check(unordered_map<int, int> &path)
    {
        int flag = 0;
        for(auto iter = path.begin(); iter != path.end(); iter ++)
        {
            if(iter->second % 2 == 1)flag ++;
        }
        if(flag <= 1) ans++;
    }

    void dfs(TreeNode *root, unordered_map<int, int> &path)
    {
        if(root == nullptr)
        return;
        path[root->val] ++;
        if(root->left == nullptr && root->right == nullptr)
        {
            check(path);
        }
        dfs(root->left, path);
        dfs(root->right, path);
        path[root->val] --;
    }





public:
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int, int> path;
        ans = 0;
        dfs(root, path);
        return ans;
    }
};
// @lc code=end

