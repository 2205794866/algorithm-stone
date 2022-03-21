/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;




class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        return (N > 0 ? quickMul(x, N) : (1.0 / quickMul(x, -N)));
    }


    double quickMul(double x, long long N)
    {
        // if(N == 0)
        //     return 1.0;
        // double y = quickMul(x, N/2);
        // return N % 2 == 0 ? y * y : y * y * x;
        double ans = 1.0;
        double x_contribute = x;
        while(N > 0)
        {
            if(N & 1 == 1)
            {
                ans *= x_contribute;
            }
            x_contribute *= x_contribute;
            N >>= 1;
        }
        return ans;
    }
};
// @lc code=end

