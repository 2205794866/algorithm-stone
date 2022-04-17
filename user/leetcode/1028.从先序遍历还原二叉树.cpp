/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] 从先序遍历还原二叉树
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
#include <map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
    TreeNode *build_tree(int layer, int &idx, vector<pair<int, int>> &mp)
    {
        if(idx >= mp.size())
        return nullptr;
        if(mp[idx].second != layer)
        return nullptr;
        TreeNode *root = new TreeNode();
        root->val = mp[idx].first;
        idx ++;
        root->left = build_tree(layer+1, idx, mp);
        root->right = build_tree(layer+1, idx, mp);
        return root;
    }


public:
    TreeNode* recoverFromPreorder(string traversal) {
        vector<pair<int, int>> mp;
        int num, layer;
        int i = 0;
        while(i<traversal.size())
        {
            num = 0, layer = 0;
            while(traversal[i] == '-')
            {
                layer++;
                i++;
            }
            while(traversal[i] >= '0' && traversal[i] <= '9')
            {
                num *= 10;
                num += traversal[i] - '0';
                i ++;
            }
            mp.push_back(make_pair(num, layer));
        }
        int idx = 0;
        return build_tree(0, idx, mp);
    }
};
// @lc code=end

