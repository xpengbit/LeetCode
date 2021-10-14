/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*Greedy Solution*/
        /*int res = 0, buy =  INT_MAX;
        for(int price : prices){
            buy = min(buy, prices);
            res = max(res, prices - buy);
        }
        return res;*/
        int n = prices.size();
        if(n == 0 || n == 1) return 0;
        vector<vector<int>> dp(n, vector<int>(2, 0));
        /*0手里没股票， 1手里有股票*/
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; i++){
            /*第i天手里没股票：i-1天就没有， i-1天有，i天卖了*/
            dp[i][0] = max(dp[i - 1][0], prices[i] + dp[i - 1][1]);
            /*第i天手里有股票：i-1天就有， i-1天没有，i天买了*/
            dp[i][1] = max(dp[i - 1][1], -prices[i]);
        }
        return dp[n-1][0];   
    }
};
// @lc code=end

