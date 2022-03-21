/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
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
    string reverseVowels(string s) {
        int i, j;
        string ans;
        ans.resize(s.size());
        i = 0, j = s.size() - 1;
        if(i == j)
        return s;
        while(i < j)
        {
            while(i < j && is_vowel(s[i]) == false)
            {
                ans[i] = s[i];
                i ++;
            }
            while (i < j && is_vowel(s[j]) == false)
            {
                /* code */
                ans[j] = s[j];
                j --;
            }
            if(i < j)
            {
                ans[j] = s[i];
                ans[i] = s[j];
                i++;
                j--;
            }
            if(i == j)
            {
                ans[i] = s[i];
            }
        }
        return ans;
    }

    bool is_vowel(char c)
    {
        auto c_list = vector<char>({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        for(auto one:c_list)
        {
            if(c == one)
            return true;
        }
        return false;
    }
};
// @lc code=end

