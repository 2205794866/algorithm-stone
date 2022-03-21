/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        std::vector<int>::iterator p1, p2;
        int MAX = 0;
        p1 = height.begin(), p2 = height.end() - 1;
        while(p1 < p2)
        {
            if(min(*p1, *p2) * (p2 - p1) > MAX)
            {
                MAX = min(*p1, *p2) * (p2 - p1);
            }
            if(*p1 < *p2)
            p1++;
            else
            p2--;
        }
        return MAX;
    }
};
// @lc code=end

