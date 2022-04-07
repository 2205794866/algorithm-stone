/*
 * @lc app=leetcode.cn id=998 lang=cpp
 *
 * [998] 最大二叉树 II
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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == nullptr || root->val < val)
        {
            TreeNode *tmp = new TreeNode(val, root, nullptr);
            return tmp;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
// @lc code=end

