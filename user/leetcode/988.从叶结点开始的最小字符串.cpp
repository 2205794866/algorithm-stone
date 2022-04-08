/*
 * @lc app=leetcode.cn id=988 lang=cpp
 *
 * [988] 从叶结点开始的最小字符串
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
    string combine;
    string ans;
public:
    void dfs(TreeNode *root)
    {   
        if(root == nullptr)
        return;
        combine.push_back('a' + root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            string temp = combine;
            reverse(combine.begin(), combine.end());
            if(ans == "" || combine < ans)
            {
                ans = combine;
            }
            combine = temp;
        }
        dfs(root->left);
        dfs(root->right);
        combine.pop_back();
    }



    string smallestFromLeaf(TreeNode* root) {
        ans = "";
        combine = "";
        dfs(root);
        return ans;
    }
};
// @lc code=end

