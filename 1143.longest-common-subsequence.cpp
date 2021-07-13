/*
 * @lc app=leetcode id=1143 lang=cpp
 *
 * [1143] Longest Common Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length(); 
        int n = text2.length();
        /*vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];*/

        /*recursion + memorization*/
        memo = vector<vector<int>>(m, vector<int>(n, -1));
        return helper(0, 0, text1, text2);
    }
private:
    vector<vector<int>> memo;
    int helper(int i, int j, string text1, string text2){
        if(i >= text1.length() || j >= text2.length()) return 0;
        if(memo[i][j] != -1) return memo[i][j];
        if(text1[i] == text2[j])
            memo[i][j] = 1 + helper(i + 1, j + 1, text1, text2);
        else
            memo[i][j] = max(helper(i, j + 1, text1, text2), helper(i + 1, j, text1, text2));
        
        return memo[i][j];
    }
};
// @lc code=end

