/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
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
// @lc code=start
class Solution {

    
public:
    int uniquePaths(int m, int n) {
        // long long ans = 1;
        // for (int x = n, y = 1; y < m; ++x, ++y) {
        //     ans = ans * x / y;
        // }
        // return ans;
        vector<vector<int>> f(m ,vector<int>(n));
        for(int i = 0; i<m; i++)
        f[i][0] = 1;
        for(int j = 0; j<n; j++)
        f[0][j] = 1;
        for(int i = 1;i < m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f[m-1][n-1];


    }



};
// @lc code=end

