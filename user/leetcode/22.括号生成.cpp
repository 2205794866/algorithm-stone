/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
    bool valid(const string&str)
    {
        int balence = 0;
        for(char c:str)
        {
            if(c == '(')
            balence++;
            else if(c == ')')
            balence --;
            if(balence < 0)
            return false;
        }
        return balence == 0;
    }
    void generate_all(string& current, int n, vector<string>& res)
    {
        if(n == current.size())
        {
            if(valid(current))
            res.push_back(current);
            return ;
        }
        current += '(';
        generate_all(current, n ,res);
        current.pop_back();
        current += ')';
        generate_all(current, n, res);
        current.pop_back();
        return ;


    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string current;
        generate_all(current, 2*n ,res);
        return res;
    }
};
// @lc code=end

