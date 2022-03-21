/*
 * @lc app=leetcode.cn id=53 lang=c
 *
 * [53] 最大子序和
 */

// @lc code=start


int maxSubArray(int* nums, int numsSize){
    int i, pre = 0, max = nums[0];
    for(i = 0; i< numsSize; i++)
    {
        pre = fmax(pre + nums[i], nums[i]);
        max = fmax(max, pre);
    }
    return max;
}
// @lc code=end

