/*
 * @lc app=leetcode.cn id=290 lang=cpp
 *
 * [290] 单词规律
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
    bool wordPattern(string pattern, string s) {
        std:vector<std::string> str_list;
        std::unordered_map<char ,string> map;
        std::unordered_map<string, char> map1;
        while(1)
        {
            int n = s.find(" ");
            if(n == s.npos)
            {
                str_list.push_back(s);
                break;
            }
            str_list.push_back(s.substr(0, n));
            s = s.substr(n+1);
        }
        // test
        // for(auto str: str_list)
        // cout<< str << endl;
        if(pattern.size() != str_list.size())
        return false;
        for(int i = 0; i<pattern.size(); i++)
        {
            auto iter = map.find(pattern[i]);
            if(iter == map.end())
            {
                map.insert(make_pair(pattern[i], str_list[i]));
            }
            else
            {
                if(iter->second != str_list[i])
                return false;
            }
            auto iter1 = map1.find(str_list[i]);
            if(iter1 == map1.end())
            {
                map1.insert(make_pair(str_list[i], pattern[i]));
            }
            else
            {
                if(iter1->second != pattern[i])
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

