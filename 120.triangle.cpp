/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*2-D*/
        /*int m = triangle.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1));
        for(int i = m - 1; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return dp[0][0];*/

        /*1-DP solution*/
        int m = triangle.size();
        vector<int> dp(triangle.back());
        for(int i = m - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0]
        ;
    }
};
// @lc code=end

