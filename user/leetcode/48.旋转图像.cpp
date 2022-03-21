/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
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
    void rotate(vector<vector<int>>& matrix) {
        /* M1 原地旋转
        int n = matrix.size();
        for(int i = 0; i<n/2; i++)
        {
            for(int j = 0; j < (n+1)/2; j++)
            {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
        M1 */

        // /* M2 两次旋转
        int n = matrix.size();
        // 水平翻转
        for(int i = 0; i<n/2; i++)
        {
            for(int j = 0; j<n; j++)
            {
                swap(matrix[i][j], matrix[n-i-1][j]);
            }
        }
        // 主对角线翻转
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // M2 */
    }
};
// @lc code=end

