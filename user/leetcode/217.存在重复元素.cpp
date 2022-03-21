/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    // /*  遍历，哈希查找
        unordered_set<int> set;
        bool flag = false;
        for(int i = 0; i<nums.size(); i++)
        {
            if(set.count(nums[i]))
            {
                flag = true;
                break;
            }
            set.insert(nums[i]);
        }
        return flag;
    
    // /*
    // // /* 位运算
    //     bool flag = false;
    //     int res = nums[0];
    //     for(int i = 1; i<nums.size(); i++)
    //     {
    //         res ^= nums[i];
    //         if(res == 0)
    //         {
    //             flag = true;
    //             break;
    //         }
    //     }
    //     return flag;
    }
};
// @lc code=end

