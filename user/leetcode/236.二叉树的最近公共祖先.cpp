/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
        return nullptr;
        if(root == p)
        return p;
        if(root == q)
        return q;
        TreeNode *L = lowestCommonAncestor(root->left, p, q);
        TreeNode *R = lowestCommonAncestor(root->right, p, q);
        if(L != nullptr && R != nullptr)
        return root;
        return (L != nullptr) ? L : R;
    }
};
// @lc code=end

