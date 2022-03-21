/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2)
        return s;
        int maxlength = 1;
        int begin = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i<n; i++)
        dp[i][i] = true;
        for(int L = 2; L<=n; L++)
        {
            for(int i = 0; i<n; i++)
            {
                int j = i+L-1;
                if(j >= n)
                {
                    break;
                }
                if(s[i] != s[j])
                dp[i][j] = false;
                else
                {
                    if(j - i < 3)
                    dp[i][j] = true;
                    else
                    {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if(dp[i][j] && L > maxlength)
                {
                    begin = i;
                    maxlength = L;
                }
            }
        }
        return s.substr(begin, maxlength);


    }
};
// @lc code=end

