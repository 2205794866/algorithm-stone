/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        int flag;
        unordered_set<int> nums;
        flag = true;
        while(n!= 1)
        {
            if(nums.find(n) != nums.end())
            {
                flag = false;
                break;
            }
            nums.insert(n);
            int x = 0;
            while(n!=0)
            {
                x += pow(n%10, 2);
                n /= 10;
            }
            n = x;
        }
        return flag;
    }
};
// @lc code=end

