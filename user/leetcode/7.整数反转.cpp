/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start

#define INT_MIN -2147483648
#define INT_MAX 2147483647
class Solution
{
public:
    int reverse(int x)
    {
        int rev = 0;
        while (x)
        {
            if (rev < INT_MIN / 10 || rev > INT_MAX / 10)
                return 0;
            rev = rev * 10 + x%10;
            x /= 10;
        }
        return rev;
    }
};
// @lc code=end
