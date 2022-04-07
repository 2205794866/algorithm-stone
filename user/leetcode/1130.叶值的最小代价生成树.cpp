/*
 * @lc app=leetcode.cn id=1130 lang=cpp
 *
 * [1130] 叶值的最小代价生成树
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
#include <stack>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        stack<int> S;
        int ans = 0;
        for(int i = 0; i<n; i++)
        {
            while(S.size() && (S.top() <= arr[i] || i==n-1))
            {
                int top = S.top();
                S.pop();
                if(!S.empty())
                {
                    ans += min(S.top(), arr[i]) * top;
                } 
                else
                {
                    ans += top * arr[i];
                }
                arr[i] = max(top, arr[i]);
            }
            S.push(arr[i]);
        }
        return ans;
    }
};
// @lc code=end

