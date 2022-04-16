/*
 * @lc app=leetcode.cn id=449 lang=cpp
 *
 * [449] 序列化和反序列化二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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

class Codec {
public:
    void string_build(TreeNode *root, string &ans)
    {
        if(root == nullptr)
        return;
        string_build(root->left, ans);
        string_build(root->right, ans);
        ans.append(to_string(root->val));
        ans.append(" ");
    }


    vector<string> split(string s, char c)
    {
        vector<string> ans;
        string temp = "";
        for(auto chr: s)
        {
            if(chr == c)
            {
                if(temp != "")
                {
                    ans.push_back(temp);
                    temp = "";
                }
                continue;
            }
            temp.push_back(chr);
        }
        return ans;
    }

    TreeNode *tree_build(int lower, int upper, vector<int>&vals)
    {
        if(vals.empty() || vals.back() < lower || vals.back() > upper)
        return nullptr;
        int val = vals.back();
        vals.pop_back();
        auto root = new TreeNode(val);
        root->right = tree_build(val, upper, vals);
        root->left = tree_build(lower, val, vals);
        return root;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        string_build(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
        return nullptr;

        vector<string> temp = split(data, ' ');
        vector<int> vals;
        for(auto str: temp)
        {
            vals.push_back(atoi(str.c_str()));
        }
        return tree_build(0x80000000, 0x7fffffff, vals);
        

    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

