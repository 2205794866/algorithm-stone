/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    void dfs(int idx, int num, int sum,int end, vector<vector<int>> &ans, vector<int> combine)
    {
        if(num == sum)
        {
            ans.push_back(combine);
            return;
        }
        for(int i = idx; i<end; i++)
        {
            combine.push_back(i);
            dfs(i+1, num+1, sum, end, ans, combine);
            combine.pop_back();
        }
    }



    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combine;
        dfs(1, 0, k, n + 1, ans, combine);
        return ans;
    }
};
// @lc code=end

