// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem437.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    unordered_map<long long, int> prefix;


    int dfs(TreeNode *root, long long curr, int targetSum)
    {
    //     if(root == nullptr)
    //     return 0;
    //     int ret = 0;
    //     if(root->val == targetSum)
    //     {
    //         ret++;
    //     }
    //     ret += dfs(root->left, targetSum-root->val);
    //     ret += dfs(root->right, targetSum-root->val);
    //     return ret;
        if(root == nullptr)
        return 0;

        int ret = 0;
        curr += root->val;
        if(prefix.count(curr - targetSum))
        {
            ret = prefix[curr-targetSum];
        }
        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;
        return ret;
    }




public:
    int pathSum(TreeNode* root, int targetSum) {
        // if(root == nullptr)
        // return 0;
        // int ret = dfs(root, targetSum);
        // ret += pathSum(root->left, targetSum);
        // ret += pathSum(root->right, targetSum);
        // return ret;
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
        
    }
};
// @lc code=end

