/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
// #include <iostream>
// #include <vector>
// #include <string>
// #include <cmath>
// #include <algorithm>
// #include <unordered_map>
// #include <unordered_set>
using namespace std;

class Solution {
    int get_max(TreeNode *root, int &maximum)
    {
        if(root == nullptr)
        return 0;
        int left_depth = get_max(root->left, maximum);
        int right_depth = get_max(root->right, maximum);
        maximum = max(maximum, left_depth + right_depth);
        return (left_depth > right_depth ? left_depth : right_depth) + 1;
    }



public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maximun = 0;
        get_max(root, maximun);
        return maximun;
    }
};
// @lc code=end

