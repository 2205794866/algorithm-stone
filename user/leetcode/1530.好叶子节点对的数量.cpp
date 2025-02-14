/*
 * @lc app=leetcode.cn id=1530 lang=cpp
 *
 * [1530] 好叶子节点对的数量
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
    /**
     * @brief 
     * 
     * @param root 
     * @param distance 
     * @return pair<vector<int>, int> 返回当前不同深度的叶子节点数目和好叶子节点数目
     */
    pair<vector<int>, int> dfs(TreeNode *root, int distance)
    {
        vector<int> depths(distance + 1, 0);
        bool isLeaf = (!root->left && !root->right);
        if(isLeaf)
        {
            depths[0] = 1;
            return make_pair(depths, 0);
        }

        vector<int> leftDepths(distance + 1, 0), rightDepths(distance + 1, 0);
        int leftCount = 0, rightCount = 0;
        if(root->left)
            tie(leftDepths, leftCount) = dfs(root->left, distance);
        if(root->right)
            tie(rightDepths, rightCount) = dfs(root->right, distance);
        for(int i = 0; i<distance; i++)
        {
            depths[i + 1] += leftDepths[i];
            depths[i + 1] += rightDepths[i];
        }
        int cnt = 0;
        for(int i = 0; i <= distance; i++)
        {
            for(int j = 0; j + i + 2 <= distance; j++){
                cnt += (leftDepths[i] * rightDepths[j]);
            }
        }
        return make_pair(depths, cnt + leftCount + rightCount);
    }









    int countPairs(TreeNode* root, int distance) {
        auto [depths, ret] = dfs(root, distance);
        return ret;
    }
};
// @lc code=end

