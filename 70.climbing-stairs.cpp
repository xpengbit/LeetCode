/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        /*if(n < 2) return n;
        int dp[n + 1];
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];*/
        memo = vector<int>(n + 1, 0);
        return helper(n);
    }
private:
    vector<int> memo;
    int helper(int n){
        if(n <= 2) return n;
        if(memo[n] != 0) return memo[n];
        return memo[n] = helper(n - 1) + helper(n - 2);
    }
};
// @lc code=end

