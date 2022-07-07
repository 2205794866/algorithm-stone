/*
 * @lc app=leetcode.cn id=1420 lang=cpp
 *
 * [1420] 生成数组
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
    int numOfArrays(int n, int m, int k) {
        const int base = 1e9 + 7;
        typedef long long LL;
        // dp[i][j] 为 当前最大值为i, search_cost 为 j
        vector<vector<LL>> dp(m+1, vector<LL>(k+1, 0));
        for(int i = 1; i<=m; i++)
        {
            dp[i][1] = 1;
        }
        for(int i = 2; i<=n; i++)
        {
            vector<vector<LL>> dpNew(m+1, vector<LL>(k+1, 0));
            int maxLen = min(i, k);
            for(int l = 1; l<=maxLen; l++)
            {
                LL presum_l = 0;
                for(int j = 1; j<=m; j++)
                {
                    dpNew[j][l] = dp[j][l] * j % base;
                    dpNew[j][l] = (dpNew[j][l] + presum_l) % base;
                    presum_l = (presum_l + dp[j][l - 1]) % base;
                }
            }
            dp = dpNew;
        }
        LL ans = 0;
        for(int i = 1; i<=m; i++)
        ans = (ans + dp[i][k]) % base;
        return ans;
    }
};
// @lc code=end

