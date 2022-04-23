/*
 * @lc app=leetcode.cn id=1339 lang=cpp
 *
 * [1339] 分裂二叉树的最大乘积
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
class Solution {
    int sum = 0;
    int best = 0;
    void dfs(TreeNode *root)
    {
        if(root == nullptr)
        return;
        sum += root->val;
        dfs(root->left);
        dfs(root->right);
    }

    int dfs2(TreeNode *root)
    {
        if(root == nullptr)
        return 0;
        int cur = dfs2(root->left) + dfs2(root->right) + root->val;
        if(abs(cur * 2 - sum) < abs(best * 2 -sum))
        best = cur;
        return cur;
    }



public:
    int maxProduct(TreeNode* root) {
        dfs(root);
        dfs2(root);
        return (long long) best * (sum - best) % 1000000007;
    }
};
// @lc code=end

