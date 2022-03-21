/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
        return intersect(nums2,nums1);
        unordered_map<int, int> m;
        for(auto num: nums1)
        {
            m[num] ++;
        }
        vector<int> ans;
        for(auto num : nums2)
        {
            if(m.count(num))
            {
                ans.push_back(num);
                m[num] --;
                if(m[num] == 0)
                    m.erase(num);
            }
        }
        return ans;


    }
};
// @lc code=end

