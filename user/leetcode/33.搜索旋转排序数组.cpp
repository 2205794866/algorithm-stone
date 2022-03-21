/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
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
public:
    int find(vector<int>& nums, int target, int begin, int end)
    {
        int res = -1;
        while(begin <= end)
        {
            int mid = (begin + end)/2;
            if(nums[mid] < target)
            begin = mid +1;
            else if(nums[mid] > target)
            end = mid -1;
            else if(nums[mid] == target)
            {
                res = mid;
                break;
            }
        }
        return res;
    }





    int search(vector<int>& nums, int target) {
        // int i = nums.size() - 2;
        // while(i >= 0 && nums[i] < nums[i + 1])
        // i--;
        // int begin, end;
        // std::cout << i << std::endl;
        // if(i < 0)
        // {
        //     begin = 0, end = nums.size() - 1;
        // }
        // else if(target >= nums[0] && target <= nums[i])
        // {
        //     begin = 0, end = i;
        // }
        // else if(target >= nums[i+1] && target <= nums[nums.size() -1])
        // {
        //     begin = i+1, end = nums.size()-1;
        // }
        // else
        // {
        //     return -1;
        // }
        // std::cout << begin <<"  "<<  end << std::endl;
        // return find(nums, target, begin, end);
        int i = nums.size() - 1;
        while(i >= 1 && nums[i] >= nums[i-1])
        {
            i --;
        }
        int flag1 = find(nums, target, 0, i-1);
        int flag2 = find(nums, target, i, nums.size() - 1);
        return (flag1 == -1 ? flag2 : flag1);
    }
};
// @lc code=end

