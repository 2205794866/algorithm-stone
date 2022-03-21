/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if (num1 == "0" || num2 == "0")
            return "0";

        
        /* 加法
        string ans = "0";
        int m = num1.length(), n = num2.length();
        for (int i = 0; i < n; i++)
        {
            string temp;
            char c = num2[n-i-1];
            int cf = 0;
            for(int j = 0; j<i; j++)
                temp.push_back('0');
            for(int j = m-1; j>=0; j--)
            {
                int x = (num1[j] - '0') * (c - '0') + cf;
                temp.push_back(x%10 + '0');
                cf = x/10;
            }
            if(cf > 0)
                temp.push_back(cf + '0');
            reverse(temp.begin(), temp.end());
            cout << temp << endl;
            ans = add_string(temp, ans);
        }
        */

        // /*乘法

        int m = num1.length(), n = num2.length();
        string ans;
        // ans.resize(m+n, '0');
        // for(int i = m-1; i>=0; i--)
        // {
        //     int x = num1[i] - '0';
        //     for(int j = n-1; j>=0; j--)
        //     {
        //         int y = num2[j] - '0';
        //         int sum = (ans[i+j+1] - '0') + x *y;
        //         ans[i+j+1] = sum %10 + '0';
        //         int t = i+j;
        //         int cf = sum / 10;
        //         while(t >= 0)
        //         {
        //             sum = ans[t] -'0' + cf;
        //             ans[t] = sum%10 + '0';
        //             cf = sum/10;
        //             t--;
        //         }
        //     }
        // }
        vector<int> arr_ans(m + n);
        for(int i = m-1; i>=0; i--)
        {
            int x = num1[i] - '0';
            for(int j = n-1; j>=0; j--)
            {
                int y = num2[j] - '0';
                arr_ans[i+j+1] += x*y;
            }
        }
        for(int i = m+n-1; i>0; i--)
        {
            arr_ans[i-1] += arr_ans[i]/10;
            arr_ans[i] %= 10;
        }
        for(int i = 0; i<m+n; i++)
        {
            ans.push_back(arr_ans[i] + '0');
        }

        if(ans[0] == '0')
            ans = ans.substr(1);
        // */
        return ans;
    }

    string add_string(string num1, string num2)
    {
        int m = num1.length(), n = num2.length();
        int i,j;
        // reverse(num1.begin(), num1.end());
        // reverse(num2.begin(), num2.end());
        string ans;
        int cf = 0;
        for(i = 0; i<max(m, n); i++)
        {
            // if(m >i && n > i)
            // {
            //     int x = (num1[m-i-1] - '0') + (num2[i] - '0') + cf;
            //     ans.push_back(x % 10 + '0');
            //     cf = x/10;
            // }
            // else if(m > i)
            // {
            //     int x = (num1[i] - '0') + cf;
            //     ans.push_back(x % 10 + '0');
            //     cf = x/10;
            // }
            // else if(n > i)
            // {
            //     int x = (num2[i] - '0') + cf;
            //     ans.push_back(x % 10 + '0');
            //     cf = x/10;
            // }
            int x = cf;
            if(m > i)
                x+= num1[m-i-1] - '0';
            if(n > i)
                x+=num2[n-i-1] - '0';
            ans.push_back(x%10 + '0');
            cf = x/10;
        }
        if(cf > 0)
        {
            ans.push_back(cf + '0');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
