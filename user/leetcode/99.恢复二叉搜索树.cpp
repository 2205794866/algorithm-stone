/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
public:
    void inorder(TreeNode *root, vector<int> &nums)
    {
        if(root == nullptr)
        return;
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    pair<int, int> findTwo(vector<int> nums)
    {
        int n = nums.size();
        int index1 = -1, index2 = -1;
        for(int i = 0; i<n-1; i++)
        {
            if(nums[i+1] < nums[i])
            {
                index2 = i+1;
                if(index1 == -1)
                    index1 = i;
                else
                    break;
            }
        }
        return {nums[index1], nums[index2]};
    }


    void recover(TreeNode *root, int x, int y)
    {
        if(root == nullptr)
        return ;
        if(root->val == x || root->val == y)
        root->val =  root->val == x ? y : x;
        recover(root->left, x, y);
        recover(root->right, x, y);
    }


    void recoverTree(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        pair<int, int> spawn = findTwo(nums);
        cout << spawn.first << endl;
        cout << spawn.second << endl;
        recover(root, spawn.first, spawn.second);
    }
};
// @lc code=end

