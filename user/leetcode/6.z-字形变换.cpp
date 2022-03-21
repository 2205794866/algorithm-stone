/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        string res = "";
        if(numRows == 1)
        return s;
        for(int i = 0; i<numRows; i++)
        {
            int j = i;
            while(j < s.length())
            {
                res += s[j];
                if(i > 0 && i<numRows-1 && j + 2*(numRows-i-1) < s.length())
                res += s[j + 2*(numRows-i-1)];
                j +=2*(numRows-1);
            }
        }
        return res;
    }
};
// @lc code=end

