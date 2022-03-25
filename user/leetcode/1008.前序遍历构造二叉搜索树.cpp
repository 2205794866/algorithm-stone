/*
 * @lc app=leetcode.cn id=1008 lang=cpp
 *
 * [1008] 前序遍历构造二叉搜索树
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

    TreeNode *dfs(int preLeft, int preRight, int inLeft, int inRight, vector<int> &preorder, unordered_map<int,int> &m)
    {
        if(preLeft > preRight || inLeft > inRight)
            return nullptr;
        int pivot = preorder[preLeft];
        TreeNode *root = new TreeNode(pivot);
        int pivotIndex = m[pivot];
        root->left = dfs(preLeft + 1, pivotIndex - inLeft + preLeft, inLeft, pivotIndex-1, preorder, m);
        root->right = dfs(pivotIndex-inLeft+preLeft+1, preRight, pivotIndex+1, inRight, preorder, m);
        return root;
    }

    // TreeNode *dfs(vector<int> &preorder, int left, int right)
    // {
    //     if(left > right)
    //     return nullptr;

    //     TreeNode *root = new TreeNode(preorder[left]);
    //     if(left == right)
    //     return root;
    //     int l = left;
    //     int r = right;
    //     while(l < r)
    //     {
    //         int mid = l + (r - l + 1) / 2;
    //         if(preorder[mid] < preorder[left])
    //         l = mid;
    //         else
    //         {
    //             r = mid-1;
    //         }
    //     }

    //     root->left = dfs(preorder, left + 1, l);
    //     root->right = dfs(preorder, l+1, right);
    //     return root;
    // }

    int idx = 0;

    TreeNode *dfs(vector<int> &preorder, int lower, int upper)
    {
        if(idx == preorder.size())
        return nullptr;

        int cur = preorder[idx];
        if(cur < lower || cur > upper)
        return nullptr;
        idx ++;
        TreeNode *root = new TreeNode(cur);
        root->left = dfs(preorder, lower, cur);
        root->right = dfs(preorder, cur, upper);
        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // int len = preorder.size();
        // unordered_map<int, int> m;
        // vector<int> inorder;
        // inorder.assign(preorder.begin(), preorder.end());
        // sort(inorder.begin(), inorder.end());

        // for(int i = 0; i < len; i++)
        //     m[inorder[i]] = i;
        
        // return dfs(0, len-1, 0, len-1, preorder, m);

        // int len = preorder.size();
        // if(len == 0)
        // return nullptr;
        // return dfs(preorder, 0, len-1);
    
        return dfs(preorder ,0x80000000, 0x7fffffff);
    }
};
// @lc code=end

