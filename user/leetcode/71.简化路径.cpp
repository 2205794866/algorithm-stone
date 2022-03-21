/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
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
    string simplifyPath(string path) {
        auto split = [](const string & s, char delim) -> vector<string>{
            vector<string> ans;
            string cur;
            for(char ch:s)
            {
                if(ch == delim)
                {
                    ans.push_back(move(cur));
                    cur.clear();
                }
                else{
                    cur +=ch;
                }
            }
            ans.push_back(move(cur));
            return ans;
        };
        vector<string> names = split(path, '/');
        vector<string> stack;
        for(string &name: names)
        {
            if(name == "..")
            {
                if(!stack.empty()){
                    stack.pop_back();
                }
            }
            else if(!name.empty() && name != "."){
                stack.push_back(move(name));
            }
        }
        string ans;
        if(stack.empty()){
            ans = "/";
        }
        else{
            for(string &name: stack){
                ans += "/" + move(name);
            }
        }
        return ans;
    }
};
// @lc code=end

