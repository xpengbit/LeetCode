/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        word1 = "#" + word1;
        word2 = "#" + word2;
        //auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));

        /*for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j){
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }

        return m + n - dp[m][n] * 2;*/
        

        auto dp = vector<vector<int>>(m + 1, vector<int>(n + 1, INT_MAX / 2));
        for(int i = 0; i <= m; ++i)
            dp[i][0] = i;
        for(int j = 0; j <= n; ++j)
            dp[0][j] = j;
        
        for(int i = 1; i <= m; ++i)
            for(int j = 1; j <= n; ++j){
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }

        return dp[m][n];
    }
};
// @lc code=end

//这个题可以有两种dp定义。1. 找LCS，然后m + n - LCS * 2; 2. 直接定义dp[i][j]为0-i， 0-j 的min steps;

