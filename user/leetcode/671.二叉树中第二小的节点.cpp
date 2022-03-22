/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
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
    void findsec(TreeNode *root, int minimum, int &ans)
    {
        if(root == nullptr)
        return;
        if(ans != -1 && root->val >= ans)
        return;
        if(root->val > minimum)
        ans = root->val;
        findsec(root->left, minimum,ans);
        findsec(root->right, minimum, ans);
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        int minimum = root->val;
        int ans = -1;
        findsec(root, minimum, ans);
        return ans;
    }
};
// @lc code=end

