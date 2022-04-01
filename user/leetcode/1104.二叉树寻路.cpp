/*
 * @lc app=leetcode.cn id=1104 lang=cpp
 *
 * [1104] 二叉树寻路
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
    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;
        int row = 0, rowstart = 1;
        while(rowstart <= label)
        {
            row ++;
            rowstart *= 2;
        }
        if(row % 2 == 0)
        label = pow(2, row) - label + pow(2, row - 1) -1;
        while(row >= 1)
        {
            if(row % 2 == 0)
                ans.push_back(pow(2, row) - label + pow(2, row-1) - 1);
            else
                ans.push_back(label);
            label = label/2;
            row --;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end

