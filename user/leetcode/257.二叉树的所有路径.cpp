/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        std::string path = to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
        }
        search_leaf(root->left, path, ans);
        search_leaf(root->right, path, ans);
        return ans;
    }


    void search_leaf(TreeNode *root, std::string path, vector<string> &ans)
    {
        if(root == nullptr)
            return;
        path += "->" + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr)
        {
            ans.push_back(path);
            return;
        }
        search_leaf(root->left, path, ans);
        search_leaf(root->right, path, ans);
    }
};
// @lc code=end

