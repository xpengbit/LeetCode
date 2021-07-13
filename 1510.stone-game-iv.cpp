/*
 * @lc app=leetcode id=1510 lang=cpp
 *
 * [1510] Stone Game IV
 */

// @lc code=start
class Solution {
public:
    bool winnerSquareGame(int n) {
        /*vector<bool> dp(n + 1, false);
        for(int i = 1; i <= n; i++){
            for(int k = 1; k*k <= i; k++){
                if(!dp[i - k*k]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];*/
        memo = vector<int>(n + 1, -1);
        return helper(n);
    }
private:
    vector<int> memo;
    bool helper(int n){
        if(memo[n] != -1) return memo[n];
        for(int i = (int)sqrt(n); i > 0; i--){
            if(!helper(n - i*i))
                return memo[n] = true;
        }
        return memo[n] = false;
    }
};
// @lc code=end

