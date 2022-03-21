/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN)
        {
            if(divisor == 1)
            {
                return INT_MIN;
            }
            if(divisor == -1)
            {
                return INT_MAX;
            }
        }
        if(divisor == INT_MIN)
        {
            return dividend == INT_MIN ? 1:0;
        }
        if(dividend == 0)
        return 0;
        bool rev = false;
        if(dividend > 0)
        {
            dividend = -dividend;
            rev = !rev;
        }
        if(divisor > 0)
        {
            divisor = -divisor;
            rev = !rev;
        }
        auto quickAdd = [](int y, int z, int x)
        {
            int result = 0, add = y;
            while (z)
            {
                /* code */
                if(z & 1)
                {
                    if(result < x- add)
                    {
                        return false;
                    }
                    result += add;
                }
                if(z != 1)
                {
                    if(add < x-add)
                    {
                        return false;
                    }
                    add += add;
                }
                z >>= 1;
            }
            return true;
            
        };
        int left = 1, right = INT_MAX, ans = 0;
        while (left <= right)
        {
            /* code */
            int mid = left+((right - left) >> 1);
            bool check = quickAdd(divisor, mid, dividend);
            if(check)
            {
                ans = mid;
                if(mid == INT_MAX)
                {
                    break;
                }
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return rev ? -ans: ans;







    }
};
// @lc code=end

