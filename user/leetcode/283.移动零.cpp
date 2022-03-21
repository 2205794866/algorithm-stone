/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = 0, b = 0;
        int n = nums.size();
        while(a < n)
        {
            if(nums[a] != 0)
            {
                swap(nums[a], nums[b]);
                a ++;
                b ++;
            }
            else
                a++;
        }
    }
};
// @lc code=end

