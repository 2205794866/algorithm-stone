/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0)
        return {newInterval};
        vector<vector<int>> ans;
        int n = intervals.size();
        int i = 0;
        while(i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i ++;
        }
        if(i == n)
        {
            ans.push_back(newInterval);
            return ans;
        }        
        if(intervals[i][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            for(;i<n; i++)
            {
                ans.push_back(intervals[i]);
            }
            return ans;
        }
        int left, right;
        left = min(intervals[i][0], newInterval[0]);
        right = max(intervals[i][1], newInterval[1]);
        i++;
        for(;i<n;i++)
        {
            if(intervals[i][0] <= right)
            {
                right = max(intervals[i][1], right);
            }
            else
            {
                ans.push_back({left, right});
                break;
            }
        }
        if(i == n)
        ans.push_back({left, right});
        for(;i<n;i++)
        ans.push_back(intervals[i]);
        return ans;
    }
};
// @lc code=end

