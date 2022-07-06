/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
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
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp;
        dp.push_back(vector<int> (1, triangle[0][0]));
        for(int i = 1; i<n; i++)
        {
            dp.push_back(vector<int> (i+1, 0));
            for(int j = 0; j<=i; j++)
            {
                if(j == 0)
                dp[i][j] = dp[i-1][j] + triangle[i][j];
                else if(j == i)
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
                else
                dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
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

