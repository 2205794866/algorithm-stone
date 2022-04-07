/*
 * @lc app=leetcode.cn id=1261 lang=cpp
 *
 * [1261] 在受污染的二叉树中查找元素
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
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class FindElements {
    void recover(TreeNode *root)
    {
        if(root == nullptr)
        return;
        if(root->left != nullptr)
        {
            root->left->val = 2*root->val + 1;
            st.insert(2*root->val + 1);
        }
        if(root->right != nullptr)
        {
            root->right->val = 2*root->val + 2;
            st.insert(2*root->val + 2);
        }
        recover(root->left);
        recover(root->right);
    }

    bool find_target(TreeNode *root, int target)
    {
        if(root == nullptr)
        return false;
        if(root->val == target)
        return true;
        return find_target(root->left, target) || find_target(root->right, target);
    }


    TreeNode *myRoot;
    unordered_set<int> st;

public:
    FindElements(TreeNode* root) {
        myRoot = root;
        root->val = 0;
        st.insert(0);
        recover(root);
    }
    
    bool find(int target) {
        // return find_target(myRoot, target);
        return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
// @lc code=end

