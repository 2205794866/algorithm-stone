/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
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

bool cmp(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

class Solution {
private:



public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int start, end;
        sort(intervals.begin(), intervals.end(),cmp);
        start = intervals[0][0], end = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++)
        {   
            if(intervals[i][0] <= end)
            {
                end = max(end, intervals[i][1]);
            }
            else
            {
                vector<int>temp = {start, end};
                ans.push_back(temp);
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        vector<int>temp = {start, end};
        ans.push_back(temp);
        return ans;
    }
};
// @lc code=end

