/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        // 递归方法
        // vector<int> a;
        // if(root != NULL)
        // {
        //     vector<int> b = inorderTraversal(root->left);
        //     for(int i = 0; i<b.size(); i++)
        //     a.push_back(b[i]);
        //     a.push_back(root->val);
        //     b = inorderTraversal(root->right);
        //     for(int i = 0; i<b.size(); i++)
        //     a.push_back(b[i]);
        // }
        // return a;



        //迭代方法
        stack<TreeNode*> S;
        vector<int> a;
        while(root != nullptr || !S.empty())
        {
            while(root != nullptr)
            {
                S.push(root);
                root = root->left;
            }
            root = S.top();
            S.pop();
            a.push_back(root->val);
            root = root->right;
        }
        return a;

    }   
};
// @lc code=end

