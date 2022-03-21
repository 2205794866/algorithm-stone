/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
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
class NumArray {
public:
    vector<int> sums;    

    NumArray(vector<int>& nums) {
        sums.push_back(0);
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     int sum = sums[i] + nums[i];
        //     sums.push_back(sum);
        // }
        for(auto num: nums)
        {
            int sum = num + sums.back();
            sums.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return (sums[right+1] - sums[left]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

