/*
 * @lc app=leetcode id=62 lang=cpp
 *
 * [62] Unique Paths
 */

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        /*2-D dp; dp[i][j] 代表在坐标i，j处的路径总数*/
        /*vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++) dp[i][0] = 1;
        for(int j = 0; j < n; j++) dp[0][j] = 1;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j -1];
            }
        }
        return dp[m - 1][n - 1];*/

        /*1-D dp.*/
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];

        /*recursive + memo*/
        /*memo = vector<vector<int>>(m, vector<int>(n, 0));
        return helper(m - 1, n - 1);*/
    }
private:
    vector<vector<int>> memo;
    int helper(int m, int n){
        if(m < 0 || n < 0) return 0;
        if(m == 0 && n == 0) return 1;
        if(memo[m][n] != 0) return memo[m][n];
        return memo[m][n] = helper(m - 1, n) + helper(m, n - 1);
    }
};
// @lc code=end

