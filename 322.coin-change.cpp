/*
 * @lc app=leetcode id=322 lang=cpp
 *
 * [322] Coin Change
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        /*2-D dp solution. dp[i][j] 表示 1---i面值的coin组成amount j 的个数*/
        /*vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        for(int i = 0; i <= coins.size(); i++ ) dp[i][0] = 0;
        for(int i = 1; i <= coins.size(); i++){
            for(int j = 1; j <= amount; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= coins[i - 1] && dp[i][j - coins[i - 1]] != INT_MAX) 
                    dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i][j]);
            }
        }
        return dp[coins.size()][amount] == INT_MAX ? -1 : dp[coins.size()][amount];*/
        
        /*1-D dp solution; dp[i]表示组成amount i需要的coin的个数*/
        /*硬币最小面值为1， 最多需要amount个硬币，初始化为amount + 1*/
        /*假设取了一个值为5的硬币，那么由于目标值是 11，所以是不是假如我们知道 dp[6]，
        那么就知道了组成 11 的 dp 值了？所以更新 dp[i] 的方法就是遍历每个硬币，
        如果遍历到的硬币值小于i值（比如不能用值为5的硬币去更新 dp[3]）时，
        用 dp[i - coins[j]] + 1 来更新 dp[i]，*/
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

