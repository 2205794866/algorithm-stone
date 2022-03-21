/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) {
    //     while(!(num >=0 && num < 10))
    //     {
    //         num = add_self(num);
    //     }
    //     return num;
    // }


    // int add_self(int x)
    // {
    //     int sum = 0;
    //     while (x > 0)
    //     {
    //         /* code */
    //         sum += x%10;
    //         x/=10;
    //     }
    //     return sum;
    return (num - 1) % 9 + 1;
    }
};
// @lc code=end

