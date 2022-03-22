/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    vector<int> ans;
    int base, count;
    int max_count;
    void update(int x)
    {
        if(x==base)
        count ++;
        else
        {
            base = x;
            count = 1;
        }
        if(count == max_count)
        ans.push_back(base);
        if(count > max_count)
        {
            max_count = count;
            ans = vector<int>{base};
        }
        
    }

    void dfs(TreeNode *root)
    {
        if(root == nullptr)
        return;
        dfs(root->left);
        update(root->val);
        dfs(root->right);
    }



    vector<int> findMode(TreeNode* root) {
        // dfs(root);
        TreeNode *cur = root, *pre = nullptr;
        while (cur)
        {
            /* code */
            if(!cur->left)
            {
                update(cur->val);
                cur = cur->right;
                continue;
            }
            pre = cur->left;
            while(pre->right && pre->right != cur)
            {
                pre = pre->right;
            }
            if(pre->right == nullptr)
            {
                pre->right = cur;
                cur = cur->left;
            }
            else
            {
                pre->right = nullptr;
                update(cur->val);
                cur = cur->right;
            }
        }
        return ans;
    }
};
// @lc code=end

