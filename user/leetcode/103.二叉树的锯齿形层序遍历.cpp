/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        return ans;
        queue<TreeNode*> Q;
        int num = 1;
        Q.push(root);
        while(!Q.empty())
        {
            int s = 0;
            vector<int> layer;
            for(int i = 0; i<num; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                layer.push_back(p->val);
                if(p->left != nullptr)
                {
                    Q.push(p->left);
                    s ++;
                }
                if(p->right != nullptr)
                {
                    Q.push(p->right);
                    s ++;
                }
            }
            ans.push_back(layer);
            num = s;
        }
        for(int i = 1; i<ans.size(); i+=2)
        reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};
// @lc code=end

