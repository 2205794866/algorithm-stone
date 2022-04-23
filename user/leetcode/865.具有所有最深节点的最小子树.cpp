/*
 * @lc app=leetcode.cn id=865 lang=cpp
 *
 * [865] 具有所有最深节点的最小子树
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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).first;
    }
    pair<TreeNode *, int> dfs(TreeNode *root)
    {
        if(root == nullptr)
        return make_pair(nullptr, 0);
        auto [Left, Ldist] = dfs(root->left);
        auto [Right, Rdist] = dfs(root->right);
        if(Ldist > Rdist) return make_pair(Left, Ldist + 1);
        if(Ldist < Rdist) return make_pair(Right, Rdist + 1);
        return make_pair(root, Ldist + 1);
    }



};
// @lc code=end

