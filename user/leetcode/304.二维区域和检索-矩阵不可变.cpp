/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
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

class NumMatrix {
    vector<vector<int>> matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        this->matrix.assign(m + 1, vector<int>(n + 1));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                this->matrix[i + 1][j + 1] = this->matrix[i+1][j] + this->matrix[i][ j + 1] - this->matrix[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->matrix[row2 + 1][col2 + 1] - this->matrix[row1][col2 + 1] - this->matrix[row2 + 1][col1] + this->matrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

