/*
 * @lc app=leetcode.cn id=576 lang=cpp
 *
 * [576] 出界的路径数
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
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int outCount = 0;
        int MOD = 1000000007;
        dp[startRow][startColumn] = 1;
        for(int i = 0; i<maxMove; i++)
        {
            vector<vector<int>> newdp(m, vector<int>(n, 0));
            for(int j = 0; j<m; j++)
            {
                for(int k = 0; k<n; k++)
                {
                    int count = dp[j][k];
                    if(count > 0)
                    {
                        for( auto direction: directions)
                        {
                            int j1 = j + direction[0], k1 = k + direction[1];
                            if(j1>=0 && j1 < m && k1 >= 0 && k1 < n)
                                newdp[j1][k1] = (newdp[j1][k1] + count) % MOD;
                            else
                                outCount = (outCount + count) % MOD;
                        }
                    }
                }
            }
            dp = newdp;
        }
        return outCount;
    }
};
// @lc code=end

