/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target){
    int low, top, mid;
    low = 0,top = numsSize-1; 
    while(low <= top)
    {
        mid = (low + top)/2;
        if(target <= nums[mid])
        {
            top = mid-1;
        }
        else
            low = mid + 1;
    }
    return low;
}
// @lc code=end

