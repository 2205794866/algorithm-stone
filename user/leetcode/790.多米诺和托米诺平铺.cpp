/*
 * @lc app=leetcode.cn id=790 lang=cpp
 *
 * [790] 多米诺和托米诺平铺
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
    int numTilings(int n) {
        int MOD = 1e9 + 7;
        if(n == 1)
        return 1;
        vector<long long> ans({1, 0, 0, 0});
        for(int i = 0; i<n; i++)
        {
            vector<long long> newAns(4);
            newAns[0] = (ans[0] + ans[3]) % MOD;
            newAns[1] = (ans[0] + ans[2]) % MOD;
            newAns[2] = (ans[0] + ans[1]) % MOD;
            newAns[3] = (ans[0] + ans[1] + ans[2]) % MOD;
            ans = newAns;
        }
        return ans[0];
    }
};
// @lc code=end

