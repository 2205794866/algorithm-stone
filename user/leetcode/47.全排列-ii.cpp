/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
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


class Solution {
public:
    vector<bool> vis;

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> combine;
        vector<vector<int>> ans;
        vis.assign(n, false);
        sort(nums.begin(), nums.end());
        get_parts(0, nums, ans, combine);
        return ans;
    }

    void get_parts(int idx, vector<int>&nums, vector<vector<int>> &ans, vector<int> combine)
    {
        if(idx == nums.size())
        {
            ans.push_back(combine);
            return ;
        }
        for(int i = 0; i<(int)nums.size(); i++)
        {
            if(vis[i] == true || (i>0 && nums[i] == nums[i-1] && vis[i-1] == false))
            continue;
            combine.push_back(nums[i]);
            vis[i] = true;
            get_parts(idx + 1, nums, ans, combine);
            vis[i] = false;
            combine.pop_back();
        }
    }


};
// @lc code=end

