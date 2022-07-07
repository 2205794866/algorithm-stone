/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
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
    int checkRecord(int n) {
        const int base = 1e9 + 7;
        int dp[2][2][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for(int i = 1; i<=n; i++)
        {
            memset(dp[1], 0, sizeof(dp[1]));
            // 以P结尾的数量
            for(int j = 0; j<=1; j++)
            {
                for(int k = 0; k<=2; k++)
                {
                    dp[1][j][0] = (dp[1][j][0] + dp[0][j][k]) % base;
                }
            }
            // 以A结尾
            for(int k = 0; k<=2; k++)
            {
                dp[1][1][0] = (dp[1][1][0] + dp[0][0][k]) % base;
            }
            // 以L结尾
            for(int j = 0; j <= 1; j++)
            for(int k = 0; k <= 1; k++)
            {
                dp[1][j][k+1] = (dp[1][j][k+1] + dp[0][j][k]) %base; 
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }
        int ans = 0;
        for(int j = 0; j<=1; j++)
        for(int k = 0; k<=2; k++)
        ans = (ans+dp[0][j][k]) % base;
        return ans;
    }
};
// @lc code=end

