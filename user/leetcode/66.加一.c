/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = (int *)malloc(sizeof(int) * (digitsSize +1));
    int i,cf;
    result[0] = 0;
    for(i = 1; i<=digitsSize; i++)
    {
        result[i] = digits[i-1];
    }
    i = digitsSize;
    result[i] += 1;
    cf = result[i]/10;
    result[i] %= 10;
    i--;
    while(i>=0)
    {
        int n = result[i] + cf;
        cf = n/10;
        result[i] = n%10;
        i--;
    }
    if(result[0] == 0)
    *returnSize = digitsSize;
    else
    *returnSize = digitsSize+1;
    return &result[digitsSize-*returnSize + 1];
}
// @lc code=end

