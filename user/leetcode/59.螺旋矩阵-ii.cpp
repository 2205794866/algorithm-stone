/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
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
    int directions[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
public:
    vector<vector<int>> generateMatrix(int n) {
        int nums = n * n;
        vector<vector<int>>matrix(n, vector<int>(n));
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        int rows = n, columns = n;
        int now_row = 0, now_column = 0;
        int direction_Index = 0;
        for(int i = 0; i<nums; i++)
        {
            matrix[now_row][now_column] = i+1;
            visited[now_row][now_column] = true;
            int next_row = now_row + directions[direction_Index][0];
            int next_column = now_column + directions[direction_Index][1];
            if(next_row < 0 || next_row >= rows || next_column < 0 || next_column >= columns || visited[next_row][next_column])
            {
                direction_Index = (direction_Index + 1) % 4;
            }
            now_row += directions[direction_Index][0];
            now_column += directions[direction_Index][1];
        }
        return matrix;
    }
};
// @lc code=end

