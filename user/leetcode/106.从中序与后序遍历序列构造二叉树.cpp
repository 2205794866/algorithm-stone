/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode * build(int postLeft, int postRight, int inLeft, int inRight, vector<int> &postorder, unordered_map<int, int> &m)
    {
        if(postLeft > postRight || inLeft > inRight)
        return nullptr;
        int pivot = postorder[postRight];
        TreeNode *root = new TreeNode(pivot);
        int pivotIndex = m[pivot];
        root->left = build(postLeft, pivotIndex-inLeft+postLeft-1, inLeft, pivotIndex-1, postorder, m);
        root->right = build(pivotIndex-inLeft+postLeft, postRight-1, pivotIndex+1, inRight, postorder, m);
        return root;
    }




public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++)
        {
            m[inorder[i]] = i;
        }
        return build(0, n-1, 0, n-1, postorder, m);
    }
};
// @lc code=end

