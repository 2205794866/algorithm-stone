/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
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
    int max_one;

    int dfs(TreeNode *root)
    {
        if(root == nullptr)
        return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int arrowLeft = 0, arrowRight = 0;
        if(root->left != nullptr && root->left->val == root->val)
        arrowLeft += left + 1;
        if(root->right != nullptr && root->right->val == root->val)
        arrowRight += right + 1;
        max_one = max(max_one, arrowLeft + arrowRight);
        return max(arrowLeft, arrowRight);
    }   


public:
    int longestUnivaluePath(TreeNode* root) {
        max_one = 0;
        dfs(root);
        return max_one;
    }
};
// @lc code=end

