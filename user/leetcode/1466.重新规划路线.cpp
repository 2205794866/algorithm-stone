/*
 * @lc app=leetcode.cn id=1466 lang=cpp
 *
 * [1466] 重新规划路线
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
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> out(n);
        vector<vector<int>> in(n);
        for(auto &con: connections) {
            out[con[0]].push_back(con[1]);
            in[con[1]].push_back(con[0]);
        }
        int res = 0;
        queue<int> q;
        vector<bool> flag(n, false);
        flag[0] = true;
        q.push(0);
        while(!q.empty())
        {
            int head = q.front();
            q.pop();
            for(auto &goin: in[head])
            {
                if(!flag[goin])
                {
                    q.push(goin);
                    flag[goin] = true;
                }
            }
            for(auto &goout: out[head])
            {
                if(!flag[goout])
                {
                    res ++;
                    flag[goout] = true;
                    q.push(goout);
                }
            }
        }
        return res; 
    }
};
// @lc code=end

