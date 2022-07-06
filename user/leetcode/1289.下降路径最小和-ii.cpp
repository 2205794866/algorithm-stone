/*
 * @lc app=leetcode.cn id=1289 lang=cpp
 *
 * [1289] 下降路径最小和  II
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int first_sum = 0, first_pos = -1, second_sum = 0;
        for(int i = 0; i<n; i++)
        {
            int fs = INT_MAX, fp = -1, ss = INT_MAX;
            for(int j = 0; j<n; j++)
            {
                int cur_sum = (first_pos != j ? first_sum: second_sum) + grid[i][j];
                if(cur_sum < fs)
                {
                    ss = fs;
                    fs = cur_sum;
                    fp = j;
                }
                else if( cur_sum < ss)
                {
                    ss = cur_sum;
                }
            }
            first_sum = fs;
            first_pos = fp;
            second_sum = ss;
        }
        return first_sum;
    }
};
// @lc code=end

