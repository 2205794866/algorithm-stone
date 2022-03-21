/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> num = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        char *cstr = new char [digits.size() + 1];
        strcpy(cstr, digits.c_str());
        int n = digits.size();
        int s = 1;
        if(n == 0)
        s = 0;
        for(int i = 0; i<n; i++)
        {
            int x = cstr[i] - '0';
            s *= num[x].size();
        }
        for(int i = 0; i<s; i++)
        {
            res.push_back("");
        }
        int rest = s;
        for(int i = 0; i<n; i++)
        {
            int x = cstr[i] - '0';
            int t = rest/num[x].size();
            rest = t;
            for(int j = 0; j<s; j++)
            {
                int l = j/t % num[x].size();
                res[j] += num[x][l];
            }
        }
        return res;
    }
};
// @lc code=end

