// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem889.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
    TreeNode *build(int preLeft, int preRight, int postLeft, int postRight, vector<int> &preorder,unordered_map<int, int> &m)
    {
        if(preLeft > preRight || postLeft > postRight)
        return nullptr;
        int pivot = preorder[preLeft];
        auto root = new TreeNode(pivot);
        if(preLeft == preRight )
        return root;
        int index = m[preorder[preLeft + 1]];
        root->left = build(preLeft+1, index - postLeft + preLeft + 1, postLeft, index, preorder, m);
        root->right = build(index - postLeft + preLeft + 2, preRight, index + 1, postRight - 1, preorder, m);
        return root;
    }




public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        unordered_map<int, int> m;
        for(int i = 0; i<n; i++)
        {
            m[postorder[i]] = i;
        }
        return build(0, n-1, 0, n-1, preorder, m);
    }
};
// @lc code=end

