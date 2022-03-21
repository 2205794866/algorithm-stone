/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() -1;
        int ans = -1;
        vector<int> res;
        while(low <= high)
        {
            int mid = (low+high) /2;
            if(nums[mid] == target)
            {
                ans = mid;
                break;
            }
            else if(nums[mid] < target)
            {
                low = mid +1;
            }
            else
            {
                high = mid -1;
            }
        }
        std::cout << ans << std::endl;
        if(ans == -1)
        {
            res.assign(2, -1);
        }
        else
        {
            int i = ans, j = ans;
            while(i >= 0 && nums[i] == nums[ans])
            i--;
            while(j <= nums.size() - 1 && nums[j] == nums[ans])
            j ++;
            res.push_back(i+1);
            res.push_back(j-1);
        }
        return res;
    }
};
// @lc code=end

