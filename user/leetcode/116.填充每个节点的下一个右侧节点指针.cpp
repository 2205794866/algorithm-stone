// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem116.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
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
    Node* connect(Node* root) {
        if(root == nullptr)
        return nullptr;
        queue<Node *> Q;
        Q.push(root);
        while(!Q.empty())
        {
            int num = Q.size();
            for(int i = 0; i<num; i++)
            {
                Node *p = Q.front();
                Q.pop();
                if(i < num-1)
                {
                    p->next = Q.front();
                }
                else
                {
                    p->next = nullptr;
                }
                if(p->left != nullptr)
                Q.push(p->left);
                if(p->right != nullptr)
                Q.push(p->right);
            }
        }
        return root;
    }
};
// @lc code=end

