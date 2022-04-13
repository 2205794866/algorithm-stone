/*
 * @lc app=leetcode.cn id=1448 lang=cpp
 *
 * [1448] 统计二叉树中好节点的数目
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
    int dfs(TreeNode *root, int max_one)
    {
        if(root == nullptr)
        return 0;
        int nums = 0;
        if(root->val >= max_one)
        {
            nums++;
            max_one = root->val;
        }
        nums += dfs(root->left, max_one);
        nums += dfs(root->right, max_one);
        return nums;
    }

    int goodNodes(TreeNode* root) {
        int max_one = 0x80000000;
        return dfs(root, max_one);
    }
};
// @lc code=end

