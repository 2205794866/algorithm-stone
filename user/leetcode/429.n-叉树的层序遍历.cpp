/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
        return ans;
        queue<Node *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int num = Q.size();
            vector<int> temp;
            for(int i = 0; i<num; i++)
            {
                Node *p = Q.front();
                Q.pop();
                temp.push_back(p->val);
                for(auto node : p->children)
                Q.push(node);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
// @lc code=end

