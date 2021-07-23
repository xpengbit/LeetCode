/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 */

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        /*dp[i][j]表示0--i面值的硬币组成j 的combination的数量*/
        /*vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        for(int i = 0; i <= coins.size(); i++) dp[i][0] = 1;
        for(int i = 1; i <= coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= coins[i - 1]) dp[i][j] += dp[i][j - coins[i - 1]];
            }
        }
        return dp[coins.size()][amount];*/

        /*1-DP solution. dp[j] 代表了组成amount j 的方法*/
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(int coin : coins){
            for(int j = coin; j <= amount; j++){
                dp[j] += dp[j - coin];
            }
        }
        return dp[amount];
    }
};
// @lc code=end

