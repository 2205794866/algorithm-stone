/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0)
        return true;
        int end, now, max_pos;
        now = end = max_pos = 0;
        while(end < nums.size() - 1)
        {
            max_pos = max(now + nums[now], max_pos);
            if(now == end)
            {
                if(end == max_pos)
                    return false;
                end = max_pos;
            }
            now ++;
        }
        return true;
    }
};
// @lc code=end

