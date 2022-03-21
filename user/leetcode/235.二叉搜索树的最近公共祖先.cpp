/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
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
        TreeNode *lchild, *rchild;
        if(root == nullptr || root == p || root == q)
        return root;
        lchild = lowestCommonAncestor(root->left, p ,q);
        rchild = lowestCommonAncestor(root->right, p, q);
        if(lchild == nullptr || rchild == nullptr)
            return lchild == nullptr ? rchild : lchild;
        else
            // std::cout << root->val << std::endl;
            return root;
    }
};
// @lc code=end

