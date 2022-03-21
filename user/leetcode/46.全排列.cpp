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
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<bool> is_added(n, false);
        vector<int> combine;
        for(int i = 0; i<n; i++)
        {
            is_added[i] = true;
            combine.push_back(nums[i]);
            get_parts(nums, is_added, combine, ans);
            combine.pop_back();
            is_added[i] = false;
        }
        return ans;
    }

    void get_parts(vector<int> nums,vector<bool>& is_added,vector<int>combine, vector<vector<int>> &ans)
    {
        
        if(combine.size() == nums.size())
        {
            ans.push_back(combine);
            return;
        }
        for(int i = 0; i<nums.size(); i++)
        {
            if(is_added[i] == false)
            {
                is_added[i] = true;
                combine.push_back(nums[i]);
                get_parts(nums, is_added, combine, ans);
                combine.pop_back();
                is_added[i] = false;
            }
        }
    }

};
// @lc code=end

