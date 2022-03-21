/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    int check(TreeNode *root, bool &flag)
    {
        if(flag == false)
        return 0;
        if(root == nullptr)
        return 0;
        int left = check(root->left, flag);
        int right = check(root->right, flag);
        if(left -right > 1 || left-right < -1)
        flag = false;
        return (left>right ? left : right)+1 ;
    }





    bool isBalanced(TreeNode* root) {
        bool flag = true;
        check(root, flag);
        return flag;
    }
};
// @lc code=end

