/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        //0 = 1000 M , 1 = 500 D, 2 = 100 C, 3 = 50 L, 4 = 10 X, 5 = 5 V, 6 = 1 I  
        std::vector<int> nums = {1000, 500, 100, 50, 10, 5, 1};
        std::vector<int> res;
        std::vector<std::string> resS = {"M", "D", "C", "L", "X", "V", "I"};
        std::string S = "";
        int i = 0;
        int n = num / nums[i];
        num %= nums[i];
        for(int j = 0; j<n; j++)
        res.push_back(i);
        while(i < 6)
        {
            int n = num / nums[i+2];
            num %= nums[i+2];
            if(n == 9)
            {
                res.push_back(i+2);
                res.push_back(i);
            }
            else if(n == 4)
            {
                res.push_back(i+2);
                res.push_back(i+1);
            }
            else
            {
                int x,y;
                x = n / 5;
                y = n % 5;
                for(int j = 0; j<x; j++)
                res.push_back(i+1);
                for(int j = 0; j<y; j++)
                res.push_back(i+2);
            }
            i = i+2;
        }
        for(int j = 0; j<res.size(); j++)
        {
            // std::cout << res[j] << std::endl;
            S += resS[res[j]];
        }
        return S;
    }
};
// @lc code=end

