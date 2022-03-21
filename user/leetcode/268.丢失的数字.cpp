/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 丢失的数字
 */

// @lc code=start
bool cmp(int a, int b)
{
    return a<b;
}
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i< nums.size(); i++)
        {
            cout << i << nums[i] << endl;
            if(i != nums[i])
            return i;
        }
        return nums.size();
    }


};
// @lc code=end

