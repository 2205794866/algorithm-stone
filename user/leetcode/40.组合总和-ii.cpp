/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;



class Solution {
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;



public:
    void dfs(int pos, int rest)
    {
        if(rest == 0)
        {
            ans.push_back(sequence);
        }
        if(pos == freq.size() || rest < freq[pos].first)
        {
            return ;
        }

        dfs(pos + 1, rest);

        int most = min(rest / freq[pos].first, freq[pos].second);
        for(int i = 1; i<=most; i++)
        {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for(int i = 1; i<= most; i++)
        {
            sequence.pop_back();
        }
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(auto num: candidates)
        {
            if(freq.empty() || num != freq.back().first)
            {
                freq.emplace_back(num, 1);
            }
            else
                ++freq.back().second;
        }
        dfs(0, target);
        return ans;
    }
};
// @lc code=end

