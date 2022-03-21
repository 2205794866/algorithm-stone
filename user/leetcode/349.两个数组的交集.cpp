/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        std::unordered_set<int> my_set;
        vector<int> ans;
        for(auto num : nums1)        
        {
            my_set.insert(num);
        }
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i<nums2.size(); i++)
        {
            if((i > 0 && nums2[i] == nums2[i-1] ) ||  my_set.count(nums2[i]) == 0)
                continue;
            ans.push_back(nums2[i]);
        }
        return ans;
    }
};
// @lc code=end

