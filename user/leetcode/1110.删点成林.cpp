/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] 删点成林
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
    vector<TreeNode *> ans;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if(root == nullptr)
        return {};
        auto iter = find(to_delete.begin(), to_delete.end(), root->val);
        if( iter == to_delete.end())
        {
            helper(root, to_delete);
            ans.push_back(root);
            return ans;
        }
        else {
            helper(root, to_delete);
            return ans;
        }
    }

    bool helper(TreeNode *root, vector<int>& to_delete)
    {
        bool k = false;
        for(auto iter = to_delete.begin(); iter!=to_delete.end(); iter ++)
        {
            if(root->val == *iter)
            {
                to_delete.erase(iter);
                k = true;
                break;
            }
        }
        if(root->left) {
            if(helper(root->left, to_delete))
            {
                root->left = nullptr;
            }
        }
        if(root->right) {
            if(helper(root->right, to_delete))
            {
                root->right = nullptr;
            }
        }
        if(k == true)
        {
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
        }
        return k;
    }

};
// @lc code=end

