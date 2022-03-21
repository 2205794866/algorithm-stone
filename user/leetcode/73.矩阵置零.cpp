/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
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
    void setZeroes(vector<vector<int>>& matrix) {
        // int m = matrix.size(), n = matrix[0].size();
        // unordered_set<int> row_set;
        // unordered_set<int> column_set;
        // for(int i = 0; i<m; i++)
        // for(int j = 0; j<n; j++)
        // {
        //     if(matrix[i][j] == 0)
        //     {
        //         row_set.insert(i);
        //         column_set.insert(j);
        //     }
        // }
        // for(int i = 0; i<m; i++)
        // for(int j = 0; j<n; j++)
        // {
        //     if(row_set.count(i) || column_set.count(j))
        //     {
        //         matrix[i][j] = 0;
        //     }
        // }
        int m = matrix.size(), n = matrix[0].size();
        bool flag_col0 = false;
        for(int i = 0; i<m; i++)
        {
            if(!matrix[i][0])
            {
                flag_col0 = true;
            }
            for(int j = 1; j<n; j++)
            {
                if(!matrix[i][j])
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i = m-1; i>=0; i--)
        {
            for(int j = 1; j<n; j++)
            {
                if(!matrix[i][0] || !matrix[0][j])
                {
                    matrix[i][j] = 0;
                }
            }
            if(flag_col0)
            matrix[i][0] = 0;
        }
    }
};
// @lc code=end

