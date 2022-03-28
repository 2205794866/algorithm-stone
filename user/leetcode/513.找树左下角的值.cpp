/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        queue<TreeNode *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int num = Q.size();
            for(int i = 0; i<num; i++)
            {
                TreeNode *p = Q.front();
                Q.pop();
                if(i == 0)
                {
                    ans = p->val;
                }
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
            }
        }
        return ans;
    }
};
// @lc code=end

