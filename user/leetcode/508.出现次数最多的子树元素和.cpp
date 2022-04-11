/*
 * @lc app=leetcode.cn id=508 lang=cpp
 *
 * [508] 出现次数最多的子树元素和
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
    int scan_tree(TreeNode *root, unordered_map<int, int> &mp, int &MAX)
    {
        if(root == nullptr)
        return 0;
        int ans = root->val;
        ans += scan_tree(root->left, mp, MAX);
        ans += scan_tree(root->right, mp, MAX);
        mp[ans] ++;
        if(mp[ans] > MAX)
        {
            MAX = mp[ans];
        }
        return ans;
    }



    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> mp;
        int MAX = 0;
        scan_tree(root, mp, MAX);
        vector<int> ans;
        for(auto it: mp)
        {
            cout << it.first << ":" << it.second << endl;
            if(it.second == MAX)
            ans.push_back(it.first);
        }
        return ans;
    }
};
// @lc code=end

