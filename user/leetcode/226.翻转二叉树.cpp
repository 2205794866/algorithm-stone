/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
public:
    /*递归
    void Exchange(TreeNode *root)
    {
        if(root == nullptr)
        return ;
        Exchange(root->left);
        TreeNode *temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        Exchange(root->left);
        return ;
    }
    */
    TreeNode* invertTree(TreeNode* root) {
        /*
        Exchange(root);
        return root;
        */
        if(root == nullptr)
        return root;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode *p = q.front();
            q.pop();
            TreeNode *temp;
            temp = p->left;
            p->left = p->right;
            p->right = temp;
            if(p->left != nullptr)
            q.push(p->left);
            if(p->right != nullptr)
            q.push(p->right);
        }
        return root;
    }
};
// @lc code=end

