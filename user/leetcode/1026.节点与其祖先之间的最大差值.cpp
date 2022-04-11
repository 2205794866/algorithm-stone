/*
 * @lc app=leetcode.cn id=1026 lang=cpp
 *
 * [1026] 节点与其祖先之间的最大差值
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
    void dfs(TreeNode *root, vector<int> &ancestor, int &ans)
    {
        if(root == nullptr)
        return;
        for(auto num: ancestor)
        {
            if(abs(num - root->val) > ans)
            ans = abs(num - root->val);
        }
        ancestor.push_back(root->val);
        dfs(root->left, ancestor, ans);
        dfs(root->right, ancestor, ans);
        ancestor.pop_back();
        return;
    }

    void dfs(TreeNode *root, int min_val, int max_val, int &ans)
    {
        if(root == nullptr)
        return;
        // ans = max(ans, max(abs(min_val - root->val), abs(max_val - root->val)));
        min_val = min(root->val, min_val);
        max_val = max(root->val, max_val);
        ans = max(ans, max_val - min_val);
        dfs(root->left, min_val, max_val, ans);
        dfs(root->right, min_val, max_val, ans);
    }



public:
    int maxAncestorDiff(TreeNode* root) {
        // vector<int> ancestor;
        int ans = 0;
        dfs(root, root->val, root->val, ans);
        return ans;
    }
};
// @lc code=end

