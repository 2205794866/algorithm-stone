/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
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
    bool check(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j, int k, string word)
    {
        if(board[i][j] != word[k])
        return false;
        else if(k == word.length() - 1)
        return true;
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for(const auto&dir:directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if(newi >=0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if(!visited[newi][newj])
                {
                    bool flag = check(board,visited,newi, newj, k+1, word);
                    if(flag == true)
                    {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        if(m * n < word.size())
        return false;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool flag = check(board, visited,i, j, 0, word);
                if(flag == true)
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

