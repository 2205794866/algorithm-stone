/*
 * @lc app=leetcode.cn id=1269 lang=cpp
 *
 * [1269] 停在原地的方案数
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
    int numWays(int steps, int arrLen) {
        typedef long long LL; 
        LL maxLen = min(arrLen, steps/2 + 1);
        vector<LL> dp(maxLen, 0);
        dp[0] = 1;
        for(int i = 1; i<=steps; i++)
        {
            vector<LL> dpNew(maxLen, 0);
            for(int j = 0; j<maxLen; j++)
            {
                dpNew[j] = dp[j];
                if(j - 1 >= 0)
                {
                    dpNew[j] = (dpNew[j] + dp[j-1]) % base;
                }
                if(j + 1< maxLen)
                {
                    dpNew[j] = (dpNew[j] + dp[j+1]) % base;
                }
            }
            dp = dpNew;
        }
        return dp[0];
    }
};
// @lc code=end

