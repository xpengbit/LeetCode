/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        /*dp[i][0]代表第i轮持有1的最大收益，dp[i][1]表示第i轮卖出1的最大收益*/
        /*dp[i][2]代表第i轮持有2的最大收益，dp[i][3]表示第i轮卖出2的最大收益*/
        dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0][2] = -prices[0], dp[0][3] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return dp[n - 1][3];
    }
};
// @lc code=end

