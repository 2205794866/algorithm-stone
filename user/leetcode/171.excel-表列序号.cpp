/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        string::iterator p;
        int res = 0;
        for(p = columnTitle.begin(); p < columnTitle.end(); p++)
        {
            res *= 26;
            res+= *p - 'A' + 1;
        }
        return res;
    }
};
// @lc code=end

