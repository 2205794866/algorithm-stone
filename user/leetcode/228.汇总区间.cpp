/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
#include<vector>
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int>::iterator p;
        vector<string> res;
        int begin, end;
        p = nums.begin();
        while(p < nums.end())
        {
            begin = *p;
            while(p+1<nums.end() && *p+1 == *(p+1))
            {
                p++;
            }
            end = *p;
            stringstream strstream;
            string s;
            if(begin == end)
            {
                strstream << begin;
                s = strstream.str();
            }
            else
            {
                strstream << begin << "->" << end;
                s = strstream.str();
            }
            res.push_back(s);
            p++;
        }
        return res;
    }
};
// @lc code=end

