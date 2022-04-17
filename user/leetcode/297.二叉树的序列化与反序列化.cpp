/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
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
    void build_string(TreeNode *root, string &ans)
    {
        if(root == nullptr)
        {
            ans.append("# ");
            return;
        }
        ans.append(to_string(root->val) + " ");
        build_string(root->left, ans);
        build_string(root->right, ans);
    }

    vector<string> split(string str, char c)
    {
        vector<string> ans;
        if(str == "")
        return ans;
        string temp = "";
        for(auto chr: str)
        {
            if(chr == c)
            {
                if(temp != "")
                ans.push_back(temp);
                temp = "";
                continue;
            }
            temp.push_back(chr);
        }
        return ans;
    }


    TreeNode* build_tree(queue<string>&str_queue)
    {
        if(!str_queue.empty())
        {
            string s = str_queue.front();
            str_queue.pop();
            if(s == "#")
            return nullptr;
            auto root = new TreeNode();
            root->val = atoi(s.c_str());
            root->left = build_tree(str_queue);
            root->right = build_tree(str_queue);
            return root;
        }
        return nullptr;
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        build_string(root, ans);
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> str_list = split(data, ' ');
        queue<string> str_queue;
        for(auto str: str_list)
        {
            str_queue.push(str);
            cout << str << endl;
        }
        return build_tree(str_queue);
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

