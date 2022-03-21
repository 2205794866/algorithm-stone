/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        // vector<int> nums1(26, 0);
        // vector<int> nums2(26, 0);
        // for(auto c: s)
        // {
        //     nums1[c-'a']++;
        // }        
        // for(auto c:t)
        // {
        //     nums2[c - 'a']++;
        // }
        // for(int i = 0; i<26; i++)
        // {
        //     if(nums1[i] != nums2[i])
        //     {
        //         return false;
        //     }
        // }
        // return true;
        map<char, int> map1;
        map<char, int> map2;
        for(auto c: s)
        {
            if(map1.count(c) == 0)
            {
                map1.insert(make_pair(c ,1));
            }
            else
            {
                map1.find(c)->second++;
            }
        }        
        for(auto c:t)
        {
            if(map2.count(c) == 0)
            {
                map2.insert(make_pair(c ,1));
            }
            else
            {
                map2.find(c)->second++;
            }
        }
        if(map1.size() != map2.size())
        return false;

        for(auto c:map1)
        {
            if(c.second != map2.find(c.first)->second)
            return false;
        }
        return true;    
    }
};
// @lc code=end

