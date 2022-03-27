/*
 * @lc app=leetcode.cn id=1305 lang=cpp
 *
 * [1305] 两棵二叉搜索树中的所有元素
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
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        stack<TreeNode *> S1, S2;
        while((!S1.empty() || root1 != nullptr) && (!S2.empty() || root2 != nullptr))
        {
            if(root1)
            {
                S1.push(root1);
                root1 = root1->left;
            }
            if(root2)
            {
                S2.push(root2);
                root2 = root2->left;
            }
            if(!(root1 || root2))
            {
                root1 = S1.top();
                root2 = S2.top();
                if(root1->val < root2->val)
                {
                    ans.push_back(root1->val);
                    S1.pop();
                    root1 = root1->right;
                    root2 = nullptr;
                }
                else
                {
                    ans.push_back(root2->val);
                    S2.pop();
                    root2 = root2->right;
                    root1 = nullptr;
                }
            } 
        }
        while(!S1.empty() || root1 != nullptr)
        {
            if(root1)
            {
                S1.push(root1);
                root1 = root1->left;
            }
            else
            {
                root1 = S1.top();
                S1.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
        }
        while(!S2.empty() || root2 != nullptr)
        {
            if(root2)
            {
                S2.push(root2);
                root2 = root2->left;
            }
            else
            {
                root2 = S2.top();
                S2.pop();
                ans.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return ans;
    }
};
// @lc code=end

