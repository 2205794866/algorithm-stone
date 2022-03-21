/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // vector<int> alphabet1(127, 0);
        // vector<int> alphabet2(127, 0);
        // string::iterator p;
        // bool flag = true;
        // for(p = s.begin(); p < s.end(); p++)
        // {
        //     alphabet1[int(*p)] ++;
        // }
        // for(p = t.begin(); p < t.end(); p++)
        // {
        //     alphabet2[int(*p)] ++;
        // }
        // sort(alphabet1.begin(), alphabet1.end());
        // sort(alphabet2.begin(), alphabet2.end());
        // for(int i = 0; i<127; i++)
        // {
        //     if(alphabet1[i] != alphabet2[i])
        //     {
        //         flag = false;
        //         break;
        //     }
        // }
        // return flag;
        bool flag = true;
        unordered_map <char, char> map1;
        unordered_map <char, char> map2;
        for(int i = 0; i<s.length(); i++)
        {
            unordered_map<char, char>::iterator p1 = map1.find(s[i]);
            unordered_map<char, char>::iterator p2 = map2.find(t[i]);
            if(p1 == map1.end() && p2 == map2.end())
            {
                map1.insert(make_pair(s[i], t[i]));
                map2.insert(make_pair(t[i], s[i]));
            }
            else if(p1 == map1.end() || p2 == map2.end())
            {
                flag = false;
                break;
            }
            else
            {
                if(p1->second != t[i] || p2->second != s[i])
                {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
};
// @lc code=end

