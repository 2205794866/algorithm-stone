/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int now;
public:
    void traversal(TreeNode *root)
    {
        if(root == nullptr)
        return ;
        traversal(root->right);
        root->val += now;
        now = root->val;
        traversal(root->left);
    }


    TreeNode* convertBST(TreeNode* root) {
        now = 0;
        traversal(root);
        return root;
    }
};
// @lc code=end

