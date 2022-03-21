/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = __INT_MAX__;
        int res2;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i-1])
            continue;
            for(int j = i + 1; j < nums.size(); j++)
            {
                if(j > i+1 && nums[j-1] == nums[j])
                continue;
                int minone = __INT_MAX__;
                int k = nums.size() - 1;
                while(j < k && abs(nums[i] + nums[j] + nums[k] - target) <= minone)
                {
                    minone = abs(nums[i] + nums[j] + nums[k] - target);
                    k--;
                }
                if(minone < res)
                {
                    res = minone;
                    res2 = nums[i] + nums[j] + nums[k+1];
                }
            }
        }
        return res2;   
    }
};
// @lc code=end

