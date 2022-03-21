/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++)
        {
            if(i > 0 && (nums[i] == nums[i-1]))
                continue;
            int k = nums.size()-1;
            int target = -nums[i];
            for(int j = i+1; j<nums.size(); j++)
            {
                if(j >i+1 && (nums[j] == nums[j-1]))
                continue;
                while(j < k && nums[j] + nums[k] > target)
                k --;
                if(j == k)
                break;
                if(nums[j] + nums[k] == target)
                {
                    vector<int> set;
                    set.push_back(nums[i]);
                    set.push_back(nums[j]);
                    set.push_back(nums[k]);
                    res.push_back(set);
                }
            }
        }
        return res;
    }
};
// @lc code=end

