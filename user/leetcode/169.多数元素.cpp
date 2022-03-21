/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // int res,cnt = 0;
        // unordered_map<int, int> map;
        // for(int i = 0; i<nums.size(); i++)
        // {
        //     map[nums[i]] ++;
        //     if(map[nums[i]] > cnt)
        //     {
        //         res = nums[i];
        //         cnt = map[nums[i]];
        //     }
        // }
        // return res;
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];

    }   
};
// @lc code=end

