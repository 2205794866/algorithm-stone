/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
    // void Inorder(TreeNode *p,vector<int> &res)
    // {
    //     if(p == nullptr)
    //     return ;
    //     Inorder(p->left, res);
    //     res.push_back(p->val);
    //     Inorder(p->right, res);
    // }

    // void Preorder(TreeNode *p,vector<int> &res)
    // {
    //     if(p == nullptr)
    //     return ;
    //     res.push_back(p->val);
    //     Preorder(p->left, res);
    //     Preorder(p->right, res);
    // }

    void PreOreder(TreeNode *p, TreeNode *q, bool &flag)
    {
        if(flag == false)
        return;
        if(p == nullptr && q == nullptr)
        return;
        else if(p != nullptr && q != nullptr)
        {
            if(p->val == q->val)
            {
                PreOreder(p->left, q->left, flag);
                PreOreder(p->right, q->right, flag);
            }
            else
            flag = false;
        }
        else
        {
            flag = false;
        }
        return ;
    }




    bool isSameTree(TreeNode* p, TreeNode* q) {
        // bool flag = true;
        // vector<int> pre1, in1;
        // vector<int> pre2, in2;
        // Inorder(p, in1);
        // Inorder(q, in2);
        // Preorder(p, pre1);
        // Preorder(q, pre2);
        // int i, j;
        // if(in1.size() != in2.size())
        // flag = false;
        // if(flag)
        // for(i=0,j=0; i<in1.size() && j <in2.size(); i++, j++)
        // {
        //     if(in1[i] != in2[j])
        //     {
        //         flag = false;
        //         break;
        //     }
        // }
        // if(flag)
        // for(i=0,j=0; i<pre1.size() && j <pre2.size(); i++, j++)
        // {
        //     if(pre1[i] != pre2[j])
        //     {
        //         flag = false;
        //         break;
        //     }
        // }
        bool flag = true;
        PreOreder(p, q, flag);
        return flag;

    }
};
// @lc code=end

