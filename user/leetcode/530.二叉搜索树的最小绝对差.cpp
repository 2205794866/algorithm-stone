/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
    void get_minone(TreeNode *root, int &pre, int& ans)
    {
        if(root == nullptr)
        return;
        get_minone(root->left, pre, ans);
        if(pre != -1)
                ans = min(root->val - pre, ans);
        pre = root->val;
        get_minone(root->right, pre, ans);

    }



    int getMinimumDifference(TreeNode* root) {
        int ans = 0x7fffffff;
        int pre = -1;
        get_minone(root, pre, ans);
        return ans;
    }
};
// @lc code=end

