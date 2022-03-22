/*
 * @lc app=leetcode id=1277 lang=cpp
 *
 * [1277] Count Square Submatrices with All Ones
 */

// @lc code=start
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int count = 0;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 1){
                dp[i][0] = 1;
                count++;
            }
        }   
        for(int j = 1; j < n; ++j){
            if(matrix[0][j] == 1){
                dp[0][j] = 1;
                count++;
            }
        }

        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 1){
                    dp[i][j] = min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                    count += dp[i][j];
                }
            }
        }
        return count;   
    }
};
// @lc code=end

