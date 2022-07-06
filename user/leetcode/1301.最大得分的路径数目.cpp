/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] 最大得分的路径数目
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
private:
    int mod = 1e9 + 7;
public:
    void update(vector<vector<pair<int,int>>> &dp,int n,int x, int y, int u, int v)
    {
        if(u >= n || v>=n || dp[u][v].first == -1)
        {
            return;
        }
        if(dp[u][v].first > dp[x][y].first)
        {
            dp[x][y] = dp[u][v];
        }
        else if(dp[u][v].first == dp[x][y].first)
        {
            dp[x][y].second += dp[u][v].second;
            if(dp[x][y].second >= mod)
            {
                dp[x][y].second -= mod;
            }
        }
    }



    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>> dp(n, vector<pair<int, int>>(n, {-1, 0}));
        for(int i = n-1, i >= 0; i--)
        for(int j = n-1; j >= 0; j--)
        {
            if(!(i == n-1 && j == n-1) && board[i][j] != 'X')
            {
                update(dp, n, i, j, i+1, j);
                update(dp, n, i, j, i, j+1);
                update(dp, n, i, j, i+1, j+1);
                if(dp[i][j].first != -1)
                {
                    dp[i][j].first += (board[i][j] == 'E' ? 0: board[i][j] - '0');
                }
            }
        }
        return dp[0][0].first == -1 ? vector<int>({0, 0}) : vector<int>{dp[0][0].first, dp[0][0].second};

    }
};
// @lc code=end

