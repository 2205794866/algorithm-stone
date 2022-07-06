/*
 * @lc app=leetcode.cn id=1155 lang=cpp
 *
 * [1155] 掷骰子的N种方法
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
    int numRollsToTarget(int n, int k, int target) {
        int base = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(1001, 0));
        for(int i = 1; i<=k ; i++)
        dp[0][i] = 1;
        for(int i = 1; i<n; i++)
        {
            dp[1].assign(target + 1, 0);
            for(int j = 1; j<=min(target, k * (i+1)); j++)
            {
                for(int l = 1; l<=min(k, j-1); l++)
                dp[1][j] = (dp[1][j] + dp[0][j-l]) % base;
            }
            dp[0].assign(dp[1].begin(), dp[1].end());
        }
        return dp[0][target];
    }
};
// @lc code=end

