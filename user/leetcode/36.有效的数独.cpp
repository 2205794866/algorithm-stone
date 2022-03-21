/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool check_column(vector<char> column)
    {
        vector<int> num(9, 0);
        for(int i = 0; i<9; i++)
        {
            if(column[i] == '.')
                continue;
            num[column[i] - '1']++;
            if(num[column[i] - '1'] == 2)
                return false;
        }
        return true;
    }


    bool check(vector<vector<char>> &board, int center_i, int center_j)
    {
        vector<int> num(9, 0);
        for(int i = center_i - 1; i<= center_i + 1; i++)
        {
            for(int j = center_j - 1; j<= center_j + 1; j++)
            {
                if(board[i][j] == '.')
                {
                    // std::cout << "1" << std::endl;
                    continue;
                }
                num[board[i][j] - '1'] ++;
                if(num[board[i][j] - '1'] == 2)
                return false;
            }
        }
        return true;
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
            if(check_column(board[i])== false)
            {
                std::cout << "1" << std::endl;
                return false;
            }
        for(int i = 0; i<9; i++)
        {
            vector<char> row;
            for(int j = 0; j<9; j++)
            {
                row.push_back(board[j][i]);
            }
            if(check_column(row) == false)
            {
                std::cout << "2" << std::endl;
                return false;
            }
        }
        for(int i = 1; i<8; i+=3)
        for(int j = 1; j<8; j+=3)
        {
            if(check(board, i, j) == false)
            {
                std::cout << "3" << i << j << std::endl;
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

