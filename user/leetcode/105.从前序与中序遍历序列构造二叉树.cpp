/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode *build(int preLeft, int preRight, int inLeft, int inRight, vector<int> &preorder, unordered_map<int, int> &m)
    {
        if(preLeft > preRight || inLeft > inRight)
        {
            return nullptr;
        }
        int pivot = preorder[preLeft];
        TreeNode *root = new TreeNode(pivot);
        int pivotIndex = m[pivot];
        root->left = build(preLeft+1, pivotIndex - inLeft + preLeft, inLeft, pivotIndex - 1, preorder, m);
        root->right = build(pivotIndex - inLeft + preLeft + 1, preRight, pivotIndex+1, inRight, preorder, m);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> m;
        int n = inorder.size();
        for(int i = 0; i<n; i++)
        {
            m[inorder[i]] = i;
        }
        return build(0, n-1, 0, n-1, preorder, m);
    }
};
// @lc code=end

