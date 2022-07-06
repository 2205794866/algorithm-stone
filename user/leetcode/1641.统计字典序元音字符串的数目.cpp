/*
 * @lc app=leetcode.cn id=1641 lang=cpp
 *
 * [1641] 统计字典序元音字符串的数目
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
    int countVowelStrings(int n) {
        vector<vector<int>> num2num({
            {0},
            {0, 1},
            {0, 1, 2},
            {0, 1, 2, 3},
            {0, 1, 2, 3, 4}
        });

        int dp[2][5];
        for(int i = 0; i<5; i++)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i<n; i++)
        {
            memset(dp[1], 0, sizeof(dp[1]));
            for(int j = 0; j<5; j++)
            {
                int nums = dp[0][j];
                for(auto n: num2num[j])
                {
                    dp[1][n] += nums;
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[1]));
        }
        int ans = 0;
        for(auto n:dp[0])
        {
            ans += n;
        }
        return ans;



    }
};
// @lc code=end

