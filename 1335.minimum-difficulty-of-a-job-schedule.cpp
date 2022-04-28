/*
 * @lc app=leetcode id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        jobDifficulty.insert(jobDifficulty.begin(), 0);

        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX/2));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i){
            for(int k = 1; k <= min(i, d); ++k){
                int mx = jobDifficulty[i];
                for(int j = i; j >= k; --j){
                    mx = max(mx, jobDifficulty[j]);
                    dp[i][k] = min(dp[i][k], dp[j - 1][k - 1] + mx);
                }
            }
        }
        return dp[n][d] >= INT_MAX/2 ? -1 : dp[n][d];        
    }
};
// @lc code=end

//第一类区间型DP

