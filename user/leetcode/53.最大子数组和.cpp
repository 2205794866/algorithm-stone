/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
    struct Status {
        int lSum, rSum, mSum, iSum;
    };


    Status pushUp(Status l, Status r)
    {
        int iSum = l.iSum + r.iSum;
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    }

    Status get(vector<int> &a, int l, int r)
    {
        if(l == r)
        {
            return Status{a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m+1, r);
        return pushUp(lSub, rSub);
    }



public:
    int maxSubArray(vector<int>& nums) {
        // int pre = 0, maxAns = nums[0];
        // for( auto num: nums)
        // {
        //     pre = max(pre+num, num);
        //     maxAns = max(pre, maxAns);
        // }
        // return maxAns;
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
// @lc code=end

