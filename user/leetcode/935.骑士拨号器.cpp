/*
 * @lc app=leetcode.cn id=935 lang=cpp
 *
 * [935] 骑士拨号器
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

class Solution
{
public:
    int knightDialer(int n)
    {
        vector<vector<int>> moveTo({{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}});
        int mod = 1e9 + 7;
        int dp[2][10];
        for(int i = 0; i<10; i++) 
        dp[0][i] = 1;



        for (int i = 1; i < n; i++)
        {
            memset(dp[1], 0, sizeof(dp[1]));
            for (int j = 0; j < 10; j++)
            {
                for(auto next: moveTo[j])
                {
                    dp[1][next] = (dp[1][next] + dp[0][j]) % mod;
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }
        long long ans = 0;
        for(int i = 0; i<10; i++)
        {
            ans = (ans + dp[0][i]) %mod;
        }
        return ans;
    }
};
// @lc code=end
