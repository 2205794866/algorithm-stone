/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
    bool search(vector<int>& nums, int low, int high, int target)
    {
        while (low <= high)
        {
            /* code */
            int mid = (low + high) / 2;
            if(nums[mid] == target)
            return true;
            else if(nums[mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }





public:
    bool search(vector<int>& nums, int target) {
        int i = nums.size() - 1;
        while(i >= 1 && nums[i] >= nums[i-1])
        {
            i --;
        }
        return search(nums, 0, i-1, target) || search(nums, i, nums.size() - 1, target); 
    }
};
// @lc code=end

