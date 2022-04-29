/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
    int get_rob(vector<int> &nums, int begin, int end)
    {
        int first = nums[begin], second = max(nums[begin], nums[begin + 1]);
        for(int i = begin + 2; i<=end; i++)
        {
            int temp = second;
            second = max(first + nums[i], second);
            first = temp;
        }
        return second;
    }


public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
        return nums[0];
        if(n == 2)
        return max(nums[0], nums[1]);
        return max(get_rob(nums, 0, n-2), get_rob(nums, 1, n-1));
    }
};
// @lc code=end

