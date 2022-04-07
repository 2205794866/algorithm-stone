/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        while(root != nullptr)
        {
            if(root->left == nullptr)
                root = root->right;
            else
            {
                TreeNode *right = root->right;
                root->right = root->left;
                root->left = nullptr;
                TreeNode *p = root->right;
                while(p->right != nullptr)
                    p = p->right;
                p->right = right;
            }
        }
    }
};
// @lc code=end

