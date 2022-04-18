/*
 * @lc app=leetcode.cn id=1443 lang=cpp
 *
 * [1443] 收集树上所有苹果的最少时间
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
    vector<int> get_parent(int n, vector<vector<int>> &edges)
    {
        vector<int> parent(n);
        vector<vector<int>> adjvex(n);
        for(auto &v : edges)
        {
            adjvex[v[0]].push_back(v[1]);
            adjvex[v[1]].push_back(v[0]);
        }
        queue<int> Q;
        Q.push(0);
        unordered_set<int> visited;
        visited.insert(0);
        while(!Q.empty())
        {
            int cur_len = Q.size();
            for(int ii = 0; ii<cur_len; ii++)
            {
                int cur = Q.front();
                Q.pop();
                for(int &nxt:adjvex[cur])
                {
                    if(visited.count(nxt) == 0)
                    {
                        visited.insert(nxt);
                        parent[nxt] = cur;
                        Q.push(nxt);
                    }
                }
            }
        }
        return parent;

    }



public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> parent = get_parent(n, edges);
        int res = 0;
        unordered_set<int> visited;
        for(int i = n-1; i>-1; i--)
        {
            if(hasApple[i] == false)
            continue;
            if(i == 0)
            continue;
            int p = i;
            while(p != 0 && visited.count(p) == 0)
            {
                visited.insert(p);
                p = parent[p];
                res += 2;
            }
        }
        return res;
    }
};
// @lc code=end

