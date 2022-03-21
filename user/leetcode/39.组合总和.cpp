/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(std::vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> &combination, int idx)
    {
        if(idx == candidates.size())
        return;

        if(target == 0)
        {
            ans.emplace_back(combination);
            return;
        }

        dfs(candidates,target,ans, combination,idx + 1);

        if(target - candidates[idx] >= 0)
        {
            combination.emplace_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combination, idx);
            combination.pop_back();
        }
    }




    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combination;
        dfs(candidates, target, ans, combination, 0);
        return ans;
    }
};
// @lc code=end

