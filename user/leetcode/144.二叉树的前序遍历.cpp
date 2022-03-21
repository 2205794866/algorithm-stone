/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    void preorder(TreeNode *root, vector<int> &res)
    {
        if(root ==nullptr)
        return ;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
        return ;
    }



    vector<int> preorderTraversal(TreeNode* root) {
        // vector<int> res;
        // if(root == nullptr)
        // return res;
        // res.push_back(root->val);
        // vector<int> left = preorderTraversal(root->left);
        // vector<int> right = preorderTraversal(root->right);
        // for(int i = 0; i<left.size(); i++)
        // res.push_back(left[i]);
        // for(int i = 0; i<right.size(); i++)
        // res.push_back(right[i]);
        // return res;
        vector<int> res;
        preorder(root, res);
        return res;

    }
};
// @lc code=end

