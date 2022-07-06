/*
 * @lc app=leetcode.cn id=1223 lang=cpp
 *
 * [1223] 掷骰子模拟
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
    typedef long long LL;



    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<LL>> dp(n + 1, vector<LL>(7));
        for(int i = 1; i<7; i++)
        {
            dp[1][i] = 1;
        }
        for(int i = 2; i<=n; i++)
        {
            for(int j = 1; j<=6; j++)
            {
                LL ans = 0;
                for(auto n: dp[i-1])
                {
                    ans = (ans + n) % base;
                }
                int idx = i - 1 - rollMax[j - 1];
                if(idx >= 1)
                {
                    for(int k = 1; k<=6; k++)
                    {
                        if(k != j)
                        {
                            ans -= dp[idx][k];
                        }
                    }
                }
                else if (idx==0)
                {
                    ans -= 1;
                }
                dp[i][j] = ans % base;
            }
        }
        LL ans = 0;
        for(auto num: dp[n])
        ans = (ans + num) % base;
        return ans;

    }
};
// @lc code=end

