/*
 * @lc app=leetcode id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        /*dp[i][j] 表示以i,j 为底边的三角形的pruduct*/
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = n -1; i >= 0; i--){
            for(int j = i + 2; j < n; j++){
                dp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; k++)
                    dp[i][j] = min(dp[i][j], values[i]* values[k]*values[j] + dp[i][k] + dp[k][j]);
            }
        }
        return dp[0][n - 1];
        
        /*dfs + memo solution will be Time Limit Exceed*/
        /*int n = values.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        return helper(values, 0, n - 1);*/
    }
private:
    vector<vector<int>> memo;
    int helper(vector<int>& values, int start, int end){
        if(end - start < 2) return 0;
        if(memo[start][end] != -1) return memo[start][end];
        int res = INT_MAX;
        for(int i = start + 1; i < end; i++){
            res = min(res, helper(values, start, i) + helper(values, i, end) + values[start]*values[i]*values[end]);
        }
        return res;
    }
};
// @lc code=end

