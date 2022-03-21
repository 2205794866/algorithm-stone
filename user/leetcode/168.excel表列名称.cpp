/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res;
        while(columnNumber > 0)
        {
            int n = columnNumber % 26;
            columnNumber /= 26;
            if(n == 0)
            {
                n = 26;
                columnNumber -= 1;
            }
            res += ('A' + n-1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

