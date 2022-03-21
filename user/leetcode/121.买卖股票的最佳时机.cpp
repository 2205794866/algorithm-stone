/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int ans = 0;
        // for(int i = 0; i<prices.size()-1; i++)
        // {
        //     for(int j = i+1; j<prices.size(); j++)
        //     {
        //         ans = max(ans, prices[j] - prices[i]);
        //     }
        // }
        // return ans;
        int maxprofit, minprice;
        maxprofit = 0; minprice = prices[0];
        for(int i = 0; i<prices.size(); i++)
        {
            maxprofit = max(maxprofit, prices[i] - minprice);
            minprice = min(minprice, prices[i]);
        }
        return maxprofit;

    }
};
// @lc code=end

