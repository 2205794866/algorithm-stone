/*
 * @lc app=leetcode.cn id=931 lang=cpp
 *
 * [931] 下降路径最小和
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
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix);
        int n = matrix.size();
        for(int i = 1; i<n; i++)
            for(int j = 0; j<n; j++)
            {
                if(j == 0)
                {
                    dp[i][j] += min(dp[i-1][j], dp[i-1][j+1]);
                }
                else if(j == n-1)
                {
                    dp[i][j] += min(dp[i-1][j-1], dp[i-1][j]);
                }
                else 
                    dp[i][j] += min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));
            }
        int ans = INT_MAX;
        for(int i = 0; i<n; i++)
        {
            if(dp[n-1][i] < ans)
            ans = dp[n-1][i];
        }
        return ans;
    }
};
// @lc code=end

