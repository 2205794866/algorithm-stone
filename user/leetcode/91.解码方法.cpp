/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
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
    bool isTrue(string s)
    {
        if(s[0] == '1')
        return true;
        if(s[0] == '2' && s[1] >= '0' && s[1] <= '6')
        return true;
        return false;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        for(int i = 1;i <=n; i++)
        {
            if(s[i-1] != '0')
            dp[i] += dp[i-1];
            if(i >1 && s[i - 2] != '0' && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26))
            dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
// @lc code=end

