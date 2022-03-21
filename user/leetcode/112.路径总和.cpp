/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    // void getSums (TreeNode *root, vector<int> &Sums, int sum)
    // {
    //     if(root == nullptr)
    //     return ;
    //     sum += root->val;
    //     if(!root->left && !root->right)
    //     {
    //         Sums.push_back(sum);
    //     }
    //     else
    //     {
    //         getSums(root->left, Sums, sum);
    //         getSums(root->right, Sums, sum);
    //     }
    //     return ;
    // }

    bool check(TreeNode *root, int targetSum, int sum)
    {
        if(root == nullptr)
        return false;
        sum += root->val;
        if(sum == targetSum && (!root->left && !root->right))
        return true;
        return check(root->left, targetSum, sum) || check(root->right, targetSum, sum);
    }



    bool hasPathSum(TreeNode* root, int targetSum) {
        // vector<int> Sums;
        // int sum = 0;
        // bool flag = false;
        // getSums(root, Sums, sum);
        // for(int i = 0; i<Sums.size(); i++)
        // {
        //     if(Sums[i] == targetSum)
        //     {
        //         flag = true;
        //         break;
        //     }
        // }
        // return flag;
        return check(root, targetSum, 0);
    }

};
// @lc code=end

