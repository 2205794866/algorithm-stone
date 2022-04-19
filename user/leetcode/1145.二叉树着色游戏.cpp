/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] 二叉树着色游戏
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
    TreeNode *getXNode(TreeNode *root, int x)
    {
        if(root == nullptr)
        return nullptr;
        if(root->val == x)
        return root;
        TreeNode *L = getXNode(root->left ,x);
        if(L == nullptr)
        {
            TreeNode *R = getXNode(root->right, x);
            return R;
        }
        return L;
    }


    int calChildNum(TreeNode *root)
    {
        if(root == nullptr)
        return 0;
        int L = calChildNum(root->left);
        int R = calChildNum(root->right);
        return L + R + 1;
    }

public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        TreeNode *xNode = getXNode(root, x);
        if(calChildNum(xNode->left) > n/2) return true;
        if(calChildNum(xNode->right) > n/2) return true;
        if(calChildNum(xNode) * 2 < n) return true;
        return false;
    }
};
// @lc code=end

