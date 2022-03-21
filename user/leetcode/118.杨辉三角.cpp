/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start

#include <vector>

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(0);
        vector<int> row;
        for(int i = 0; i<numRows; i++)
        {
            res.push_back(row);
            for(int j = 0; j<=i; j++)
            {
                if(j == 0 || j== i)
                {
                    res[i].push_back(1);
                }
                else
                {
                    int x = res[i-1][j-1] + res[i-1][j];
                    res[i].push_back(x);
                }
            }
        }
        return res;
    }
};
// @lc code=end

