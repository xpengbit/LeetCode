/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        /*dp[i][0] 第i天持有，dp[i][1]第i天卖出，dp[i][2]第i天卖出一天以上*/
        dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0][2] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
        }
        return max(dp[n - 1][2], dp[n - 1][1]);
    }
};
// @lc code=end

