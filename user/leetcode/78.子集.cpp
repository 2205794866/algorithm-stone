/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
    vector<vector<int>> ans;
    vector<int> combine;

    void dfs(int now, int num, vector<int> &nums)
    {
        if(now == num)
        {
            ans.push_back(combine);
            return;
        }
        combine.push_back(nums[now]);
        dfs(now + 1, num, nums);
        combine.pop_back();

        dfs(now + 1, num, nums);
    }


public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // dfs(0, nums.size(), nums);
        // return ans;
        int n = nums.size();
        for(int mask = 0; mask<(1 << n); mask++)
        {
            combine.clear();
            for(int i = 0; i<n; i++)
            {
                if(mask & (1 << i))
                combine.push_back(nums[i]);
            }
            ans.push_back(combine);
        }
        return ans;
    }
};
// @lc code=end

