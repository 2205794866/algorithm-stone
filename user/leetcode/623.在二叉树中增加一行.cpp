/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
        return new TreeNode(val, root, nullptr);

        int now_depth = 1;
        queue<TreeNode *> Q;
        Q.push(root);
        while(now_depth < depth - 1)
        {
            int n = Q.size();
            for(int i = 0; i<n; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
            }
            now_depth ++;
        }
        int n = Q.size();
        for(int i = 0; i<n; i++)
        {
            TreeNode *p = Q.front();
            Q.pop();
            TreeNode *left = new TreeNode(val, p->left, nullptr);
            TreeNode *right = new TreeNode(val, nullptr, p->right);
            p->left = left;
            p->right = right;
        }
        return root;
    }
};
// @lc code=end

