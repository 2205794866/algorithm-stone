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


struct UnionFind {
    vector<int> ancestor;
    UnionFind(int n)
    {
        ancestor.resize(n);
        for(int i = 0; i<n; i++)
        {
            ancestor[i] = i;
        }
    }

    int find(int index)
    {
        return index == ancestor[index] ? index: ancestor[index] = find(ancestor[index]);
    }

    void merge(int u, int v)
    {
        ancestor[find(u)] = find(v);
    }
};

public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind uf = UnionFind(n + 1);
        auto parent = vector<int>(n + 1);
        for(int i = 1; i<=n; i++)
        parent[i] = i;
        int conflict = -1;
        int cycle = -1;
        for(auto i = 0; i<n; i++)
        {
            auto edge = edges[i];
            int node1 = edge[0], node2 = edge[1];
            if(parent[node2] != node2)
            conflict = i;
            else 
            {
                parent[node2] = node1;
                if(uf.find(node1) == uf.find(node2))
                cycle = i;
                else
                uf.merge(node1, node2);
            }
        }
        if(conflict < 0)
        {
            return {edges[cycle][0], edges[cycle][1]};
        }
        else {
            auto conflicEdge = edges[conflict];
            if( cycle >= 0) {
                return {parent[conflicEdge[1]], conflicEdge[1]};
            }
            else {
                return {conflicEdge[0], conflicEdge[1]};
            }
        }


    }
};
// @lc code=end

