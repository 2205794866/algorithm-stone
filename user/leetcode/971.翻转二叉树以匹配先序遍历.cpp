/*
 * @lc app=leetcode.cn id=971 lang=cpp
 *
 * [971] 翻转二叉树以匹配先序遍历
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
    void dfs(TreeNode *p, vector<int> &flipped, vector<int> &voyage, int& index)
    {
        if(p != nullptr)
        {
            if(p->val != voyage[index ++]){
                // flipped.swap(vector<int>());
                vector<int>().swap(flipped);
                flipped.push_back(-1);
                return;
            }
            if (index < voyage.size() && p->left != nullptr && p->left->val != voyage[index])
            {
                flipped.push_back(p->val);
                dfs(p->right, flipped, voyage, index);
                dfs(p->left, flipped, voyage, index);
            }
            else
            {
                dfs(p->left, flipped, voyage, index);
                dfs(p->right, flipped, voyage, index);
            }

        }

    }



public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> flipped;
        int index = 0;
        dfs(root, flipped, voyage, index);
        if(!flipped.empty() && flipped[0] == -1)
        {
            // flipped.swap(vector<int>());
            vector<int>().swap(flipped);
            flipped.push_back(-1);
        }
        return flipped;
    }
};
// @lc code=end

