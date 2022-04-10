/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] 二叉树中的最长交错路径
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
    int getLength(TreeNode *root)
    {
        int L = 0;
        TreeNode *p = root->left;
        while(p)
        {
            if(L % 2 == 0)
            {
                p = p->right;
                L++;
            }
            else
            {
                p = p->left;
                L++;
            }
        }
        int R = 0;
        p = root->right;
        while(p)
        {
            if(R % 2 == 0)
            {
                p = p->left;
                R++;
            }
            else
            {
                p = p->right;
                R++;
            }
        }
        return max(L, R);
    }

    int maxLen;
    // 0 => left, 1 => right
    void dfs(TreeNode *root, bool dir, int len)
    {
        maxLen = max(maxLen, len);
        if(dir == 0)
        {
            if(root->left) dfs(root->left, 1, len+1);
            if(root->right) dfs(root->right, 0, 1);
        }
        else
        {
            if(root->left) dfs(root->left, 1, 1);
            if(root->right) dfs(root->right, 0, len+1);
        }
    }

    pair<int, int> dfs(TreeNode *root)
    {
        if(root == nullptr)
        return {0, 0};
        auto [ll, lr] = dfs(root->left);
        auto [rl, rr] = dfs(root->right);
        maxLen = max(maxLen, max(1 + lr, 1 + rl));
        return {1 + lr, 1 + rl};
    }



public:
    int longestZigZag(TreeNode* root) {
        // if(root == nullptr)
        // return -1;
        // int L = longestZigZag(root->left);
        // int R = longestZigZag(root->right);
        // int N = getLength(root);
        // return max(N, max(L, R));
        // if(root == nullptr)
        // return 0;
        // maxLen = 0;
        // dfs(root, 0, 0);
        // dfs(root, 1, 0);
        // return maxLen;
        dfs(root);
        return max(0, maxLen - 1);
    }
};
// @lc code=end

