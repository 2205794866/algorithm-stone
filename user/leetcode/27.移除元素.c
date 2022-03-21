/*
 * @lc app=leetcode.cn id=27 lang=c
 *
 * [27] 移除元素
 */

// @lc code=start


int removeElement(int* nums, int numsSize, int val){
    int i,j;
    for(i = 0; i<numsSize; i++)
    {
        if(nums[i] == val)
        {
            for(j = i+1; j<numsSize; j++)
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

