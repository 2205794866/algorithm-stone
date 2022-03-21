/*
 * @lc app=leetcode.cn id=326 lang=cpp
 *
 * [326] 3 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfThree(int n) {
        // if(n <= 0)
        // return false;

        // while (n!=1 & n!=-1)
        // {
        //     /* code */
        //     if(n%3 != 0)
        //     return false;
        //     n /= 3;
        // }
        // return true;
        return n>0&&1162261467%n==0;
    }
};
// @lc code=end

