/*
 * @lc app=leetcode.cn id=662 lang=cpp
 *
 * [662] 二叉树最大宽度
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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        vector<unsigned long long> cur_node_num;
        queue<TreeNode *> Q;
        cur_node_num.push_back(0);
        Q.push(root);
        unsigned long long max_len = 0;
        while(!Q.empty())
        {
            int n = Q.size();
            unsigned long long left = 0;
            unsigned long long right = 0;
            vector<unsigned long long> now_node_num;
            for(int i =0; i<n; i++)
            {
                unsigned long long num = cur_node_num[i];
                TreeNode *p = Q.front();
                Q.pop();
                if(p->left != nullptr)
                {
                    Q.push(p->left);
                    right = num *2+1;
                    now_node_num.push_back(right);
                    if(left == 0)
                        left = right;
                }
                if(p->right != nullptr)
                {
                    Q.push(p->right);
                    right = num * 2+2;
                    now_node_num.push_back(right);
                    if(left == 0)
                        left = right;
                }
            }
            max_len = max(max_len, right - left+1);
            cur_node_num.assign(now_node_num.begin(), now_node_num.end());
        }
        return max_len;
    }
};
// @lc code=end

