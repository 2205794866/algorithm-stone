#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */

// @lc code=start
class Solution {
public:
    bool isUgly(int n) {
        // if(n <= 0)
        //     return false;

        // for(int i = 2; i<=n/2; i++)
        // {
        //     if(i % 2 != 0 && i % 3 != 0 && i % 5 != 0)
        //     {
        //         if(n % i == 0)
        //             return false;
        //     }
        // }
        // if(n != 1 && n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
        //     return false;
        if(n <= 0)
        return false;
        vector<int> factors = {2, 3 ,5};
        for(auto factor: factors)
        {
            while(n % factor == 0)
            {
                n /= factor;
            }
        }
        return n == 1;
    }
};
// @lc code=end

