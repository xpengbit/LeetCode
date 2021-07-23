/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        int res = INT_MIN;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0) {
                    if(matrix[i][j] == '1') dp[i][j] = 1;
                }
                else{
                    if(matrix[i][j] == '1') 
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res * res;    
    }
};
// @lc code=end

