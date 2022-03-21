/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    // bool isEque(TreeNode *left, TreeNode *right)
    // {
    //     if(!left && !right)
    //     return true;
    //     else if(!left || !right)
    //     return false;
    //     else
    //     return left->val == right->val && isEque(left->left, right->right) && isEque(left->right, right->left);
    // }


        bool check(TreeNode *u, TreeNode *v)
        {
            queue<TreeNode *> q;
            q.push(u), q.push(v);
            while(!q.empty())
            {
                u = q.front(); q.pop();
                v = q.front(); q.pop();
                if(!u && !v) continue;
                else if((!u || !v) || (u->val != v->val)) return false;

                q.push(u->left);
                q.push(v->right);
                q.push(u->right);
                q.push(v->left);
            }
            return true;
        }



    bool isSymmetric(TreeNode* root) {  
        // 递归
        // return isEque(root->left, root->right);
        return check(root, root);

    }
};
// @lc code=end

