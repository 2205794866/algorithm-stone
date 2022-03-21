/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
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
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++)
        {
            ans.emplace_back(cal_n(i));
        }
        return ans;
    }
    int cal_n(int n)
    {
        int num = 0;
        while(n != 0)
        {
            if(n & 1 == 1)
            {
                num ++;
            }
            n >>= 1;
        }
        return num;
    }
};
// @lc code=end

