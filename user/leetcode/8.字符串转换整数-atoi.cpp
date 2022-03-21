/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        const int MAXINT = 2147483647;
        const int MININT = -2147483648;
        int flag = 1;
        int res = 0;
        int i = 0;
        while(i<s.length() && s[i] == ' ')
        i++;
        if(i == s.length())
        return res;
        if(s[i] == '-')
        {
            flag = -1;
        }
        if(s[i] == '-' || s[i] == '+')
        i++;
        while(i<s.length() && s[i] >= '0' && s[i] <='9')
        {
            if(flag == 1)
            {
                if((MAXINT - s[i] + '0' )/10 < res)
                {
                    res = MAXINT;
                    break;
                }
            }
            else
            {
                if((MAXINT - s[i] + '0' )/10 <= res - 1)
                {
                    res = MININT;
                    break;
                }
            }
            res *= 10;
            res += s[i] - '0';
            i++;
        }
        if(res != MININT && flag == -1)
        res = -res;
        return res;
    }
};
// @lc code=end

