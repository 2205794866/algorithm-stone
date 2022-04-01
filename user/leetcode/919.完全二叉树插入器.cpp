/*
 * @lc app=leetcode.cn id=919 lang=cpp
 *
 * [919] 完全二叉树插入器
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

class CBTInserter {
    vector<TreeNode *> tree;
public:
    CBTInserter(TreeNode* root) {
        if(root == nullptr)
        return;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            TreeNode *p = Q.front();
            Q.pop();
            tree.push_back(p);
            if(p->left != nullptr)
            Q.push(p->left);
            if(p->right != nullptr)
            Q.push(p->right);
        }
    }
    
    int insert(int val) {
        int n = tree.size();
        TreeNode *p = new TreeNode(val);
        TreeNode *parent;
        tree.push_back(p);
        parent = tree[(n-1)/2];
        if(n % 2 == 1)
        parent->left = p;
        else
        parent->right = p;
        return parent->val;
    }
    
    TreeNode* get_root() {
        if(tree.size() == 0)
        return nullptr;
        return tree[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */
// @lc code=end

