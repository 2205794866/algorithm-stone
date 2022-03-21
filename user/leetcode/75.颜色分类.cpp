/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
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

class Solution
{
public:
    void quick_sort(vector<int> &nums, int left, int right)
    {
        if (left >= right)
            return;
        int base = nums[left];
        int i, j;
        i = left, j = right;
        while (i < j)
        {
            while (nums[j] >= base && j > i)
                j--;
            while (nums[i] <= base && j > i)
                i++;
            if (i < j)
            {
                swap(nums[i], nums[j]);
            }
        }
        nums[left] = nums[i];
        nums[i] = base;
        quick_sort(nums, left, i - 1);
        quick_sort(nums, i + 1, right);
    }

    void sortColors(vector<int> &nums)
    {
        quick_sort(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
