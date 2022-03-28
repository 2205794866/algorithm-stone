/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        int max_one, num;
        if(root == nullptr)
        return ans;
        queue<TreeNode *> Q;
        Q.push(root);
        while (!Q.empty())
        {
            /* code */
            max_one = 0x80000000;
            num = Q.size();
            for(int i = 0; i<num; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                max_one = max(p->val, max_one);
                // if(p->val > max_one)
                // max_one = p->val;
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
            }
            ans.push_back(max_one);
        }
        return ans;
    }
};
// @lc code=end

