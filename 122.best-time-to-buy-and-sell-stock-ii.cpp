/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*Greedy Solution*/
        int res = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i - 1])
                res += prices[i] - prices[i - 1];
        }
        return res;

        /*DP Solution*/
        /*if(prices.empty()) return 0;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];*/    
    }
};
// @lc code=end

