/*
 * @lc app=leetcode.cn id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start


int mySqrt(int x){
    int i;
    for(i = 1; i * i <= x; i++);
    return i-1;
    
}
// @lc code=end

