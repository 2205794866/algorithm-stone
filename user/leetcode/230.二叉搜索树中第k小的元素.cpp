/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int now = 0;

public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == nullptr)
        return -1;
        int L = kthSmallest(root->left, k);
        now++;
        if(now == k)
            return root->val;
        int R = kthSmallest(root->right, k);
        return L == -1 ? R : L;
    }
};
// @lc code=end

