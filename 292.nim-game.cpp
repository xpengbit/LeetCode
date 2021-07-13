/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 */

// @lc code=start
class Solution {
public:
    bool canWinNim(int n) {
        /*vector<bool> memo(n + 1);
        return dfs(n, memo);*/

        /*iterative solution*/
        /*vector<bool> dp(max(n + 1, 4));
        dp[1] = dp[2] = dp[3] = true;

        for(int i = 4; i <= n; i++){
            dp[i] = !dp[i - 1] || !dp[i - 2] || !dp[i - 3];
        }
        return dp[n];*/
        return n % 4 != 0;
    }
private:
    bool dfs(int n, vector<bool> memo){
        if(n < 0) return false;
        if(memo[n] != NULL) return memo[n];
        bool res = false;
        for(int i = 1; i <= 3; i++)
            if(n >= i) res |= !dfs(n - i, memo);
        
        return memo[n] = res;
    }
};
// @lc code=end

