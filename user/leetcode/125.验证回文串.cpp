/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string t = "", t1;
        string::iterator iter;
        for(iter = s.begin(); iter != s.end(); iter++)
        {
            if((*iter >= '0' && *iter <= '9') || (*iter >= 'a' && *iter <= 'z'))
            t += *iter;
            else if(*iter >= 'A' && *iter <= 'Z')
            {
                t += (*iter + 'a' - 'A');
            }
        }
        t1 = t;
        reverse(t1.begin(), t1.end());
        if(t1 == t)
        return true;
        else
        return false;
    }
};
// @lc code=end

