/*
 * @lc app=leetcode id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

// @lc code=start
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(n + 1, vector<int>(minProfit + 1, 0)); //dp[person][profit]表示n个人恰好产生profit利润的方案数
        int M = 1e9 + 7;
        auto dp_new = dp;
        dp[0][0] = 1;
        for(int k = 0; k < group.size(); ++k){
            int x = group[k];
            int y = profit[k];
            dp_new = dp;
            for(int i = 0; i <= n; ++i){
                for(int j = 0; j <= minProfit; ++j){
                    if(i + x <= n){
                        dp_new[i + x][min(j + y, minProfit)] += dp[i][j];
                        dp_new[i + x][min(j + y, minProfit)] %= M;
                    }
                }
            }
            dp = dp_new;
        }
        int ret = 0;
        for(int i = 0; i <= n; ++i)
            ret = (ret + dp[i][minProfit]) % M;

        return ret;
    }
};
// @lc code=end

