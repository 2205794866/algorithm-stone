/*
 * @lc app=leetcode.cn id=685 lang=cpp
 *
 * [685] 冗余连接 II
 */

// @lc code=start
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
    int Find(vector<int> &parent, int index)
    {
        if(parent[index] != index)
        Find(parent, parent[index]);
        return parent[index];
    }


    void Union(vector<int> &parent, int node1, int node2)
    {
        parent[Find(parent, node2)] = Find(parent, node1);
    }



public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i<n+1; i++)
        parent[i] = i;
        for(auto &edge: edges)
        {
            int node1 = edge[0], node2 = edge[1];
            if(Find(parent, node1) != Find(parent, node2))
            {
                Union(parent, node1, node2);
            }
            else
                return edge;
        }
        return vector<int> {};
    }
};
// @lc code=end

