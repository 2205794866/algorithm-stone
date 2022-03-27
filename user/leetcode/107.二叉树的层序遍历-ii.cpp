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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        return ans;
        queue<TreeNode *> Q;
        Q.push(ans);
        while(!Q.empty())
        {
            int num = Q.size();
            vector<int> temp;
            for(int i = 0; i<num; i++)
            {
                TreeNode *p = Q.top();
                Q.pop();
                temp.push_back(p->val);
                if(p->left != nullptr)
                    Q.push(p->left);
                if(p->right != nullptr)
                    Q.push(p->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};