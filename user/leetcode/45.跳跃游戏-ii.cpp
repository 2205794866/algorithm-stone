#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start

class Solution {
public:

    int jump(vector<int>& nums) {
        // TLE
        // int min = 1000;
        // jump_to_end(0, 0, min, nums);
        int step;
        int end, now, max_pos;
        int n = nums.size() - 1;
        max_pos = step = now = end = 0;

        while (end < n)
        {
            /* code */
            max_pos = max(max_pos, now+nums[now]);
            if(now == end)
            {
                step++;
                end = max_pos;
            }
            now++;
        }
        return step;
    }

    void jump_to_end(int now, int steps,int &min,vector<int>& nums)
    {
        if(now == nums.size() - 1)
        {
            if(steps < min)
                min = steps;
            cout << min << endl;
            return;
        }
        for(int i = 1; i < nums.size() - now && i<=nums[now]; i++)
        {
            jump_to_end(now + i, steps+1, min, nums);
        }
    } 
};
// @lc code=end

