/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
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
    // int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // if(matrix.size() == 0 || matrix[0].size() == 0)
        // return {};
        // int rows = matrix.size(), columns = matrix[0].size();
        // vector<vector<bool>> visited(rows, vector<bool>(columns,false));
        // int total = rows * columns;
        // vector<int> order;
        // int direction_Index = 0;
        // int row = 0;
        // int column = 0;
        // for(int i = 0; i<total; i++)
        // {
        //     order.push_back(matrix[row][column]);
        //     visited[row][column] = true;
        //     int next_row = row + directions[direction_Index][0];
        //     int next_column = column + directions[direction_Index][1];
        //     if(next_row < 0 ||  next_row >= rows || next_column < 0 || next_column >= columns || visited[next_row][next_column])
        //     {
        //         direction_Index = (direction_Index+1) % 4;
        //     }
        //     row = row + directions[direction_Index][0];
        //     column = column + directions[direction_Index][1];
        // }
        // return order;

        if(matrix.size() == 0 || matrix[0].size() == 0)
        return {};

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> order;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom)
        {
            for(int column = left; column <= right; column ++)
            {
                order.push_back(matrix[top][column]);
            }
            for(int row = top + 1; row <= bottom ; row ++)
            {
                order.push_back(matrix[row][right]);
            }
            if(left < right && top < bottom)
            {
                for(int column = right - 1; column > left; column --)
                {
                    order.push_back(matrix[bottom][column]);
                    // cout << bottom << column << endl;
                }
                for(int row = bottom; row > top; row --)
                {
                    order.push_back(matrix[row][left]);
                }
            }
            left ++;
            right --;
            top ++;
            bottom --;
            // cout << left << right << top << bottom << endl;
        }
        return order;


    }
};
// @lc code=end

