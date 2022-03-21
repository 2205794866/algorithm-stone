/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0)
        return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>>f(m, vector<int>(n));
        bool flag = false;
        for(int i = 0; i<m; i++)
        {
            if(obstacleGrid[i][0] == 1)
            flag = true;
            if(flag)
                f[i][0] = 0;
            else
                f[i][0] = 1;
        }
        flag = false;
        for(int j = 0; j<n; j++)
        {
            if(obstacleGrid[0][j] == 1)
            flag = true;
            if(flag)
                f[0][j] = 0;
            else
                f[0][j] = 1;
        }
        for(int i = 1; i<m; i++)
        for(int j = 1; j<n; j++)
        {
            if(obstacleGrid[i][j] == 1)
            f[i][j] = 0;
            else
            f[i][j] = f[i-1][j] + f[i][j-1];
        }
        return f[m-1][n-1];
    }
};
// @lc code=end

