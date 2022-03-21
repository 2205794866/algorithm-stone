/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize){
    int i, j;
    for(i = 1; i<numsSize; i++)
    {
        if(nums[i] == nums[i-1])
        {
            for(j = i+1; j < numsSize; j++)
            {
                nums[j-1] = nums[j];
            }
            i--;
            numsSize--;
        }
    }
    return numsSize;
}
// @lc code=end

