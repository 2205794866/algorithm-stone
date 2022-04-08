/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] 最深叶节点的最近公共祖先
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
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        if(root == nullptr)
        return make_pair(nullptr, 0);
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left.second > right.second) return make_pair(left.first, left.second + 1);
        if(left.second < right.second) return make_pair(right.first, right.second + 1);
        return make_pair(root, left.second + 1);
    }




public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).first;
    }
};
// @lc code=end

