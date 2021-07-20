/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [1216] Valid Palindromic III
 */

// @lc code=start
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        /*solution 1: use LCS, 把string反转， 求两个sting的LCS. 与string length相减*/
        /*string scopy(s);
        std::reverse(scopy.begin(), scopy.end());
        return s.length() - lcs(s, scopy) <= k;*/

        /*solution 2: 找出s的最长回文子序列。然后与sring的length相减是否<=k*/
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >= 0; i--){
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
                else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return n - dp[0][n] <= k;
    }
private:
    int lcs(string s, string r){
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(s[i] == r[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n][n];
    }
};
// @lc code=end

