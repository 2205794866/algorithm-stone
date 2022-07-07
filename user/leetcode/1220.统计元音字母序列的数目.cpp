/*
 * @lc app=leetcode.cn id=1220 lang=cpp
 *
 * [1220] 统计元音字母序列的数目
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
    const int base = 1e9 + 7;
    int countVowelPermutation(int n) {
        int dp[2][5];
        vector<vector<int>> num2num({
            {1},
            {0, 2},
            {0, 1, 3, 4},
            {2, 4},
            {0}
        });
        for(int i = 0; i<5;i ++)
        {
            dp[0][i] = 1;
        }
        for(int i = 1; i<n; i++)
        {
            memset(dp[1], 0, sizeof(dp[1]));
            for(int j = 0; j < 5; j++)
            {
                int n = dp[0][j];
                for(auto num: num2num[j])
                {
                    dp[1][num] = (dp[1][num] + n) % base;
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }
        int ans = 0;
        for(auto n: dp[0])
        {
            ans = (ans + n) % base;
        }
        return ans;
    }
};
// @lc code=end

