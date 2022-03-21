/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low, high;
        low = 0, high = m-1;
        while (low <= high)
        {
            /* code */
            int mid = (low+high) / 2;
            if(target >= matrix[mid][0])
            {
                low = mid + 1;
            }
            else
            {
                high = mid-1;
            }
        }
        int row = low-1;
        if(row < 0 || row > m-1)
            return false;
        if(matrix[row][n-1] < target)
        return false;

        if(n == 1)
        {
            if(target == matrix[row][0])
            return true;
            else
            return false;
        }
        low = 0, high = n-1;
        while (low <= high)
        {
            /* code */
            int mid = (low + high) / 2;
            if(target == matrix[row][mid])
            return true;
            else if(target < matrix[row][mid])
            high = mid-1;
            else 
            {
                low = mid + 1;
            }
        }
        return false;        
    }
};
// @lc code=end

