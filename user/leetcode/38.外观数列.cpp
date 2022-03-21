/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
        return "1";
        std::string old_one = countAndSay(n - 1);
        std::string new_one = "";
        int i = 0;
        while(i < old_one.length())
        {
            int num = 1;
            char c = old_one[i];
            i ++;
            while(i < old_one.length() && old_one[i] == c)
            {
                i++;
                num ++;
            }
            new_one += to_string(num);
            new_one += c;
        }
        return new_one;
    }
};
// @lc code=end

