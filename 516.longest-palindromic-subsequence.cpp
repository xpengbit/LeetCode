/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        /*DFS + memo solution; Will be TLE*/
        /*if(s.empty()) return 0;
        int n = s.size();
        m_ = vector<vector<int>>(n, vector<int>(n, -1));
        return dfs(s, 0, n - 1);*/
        
        if(s.empty()) return 0;
        int n = s.size();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        for(int i = n - 1; i >= 0; --i){
            dp[i][i] = 1;
            for(int j = i + 1; j < n; j++){
                if(s[j] == s[i]) dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
private:
    vector<vector<int>> m_;
    int dfs(string s, int i, int j){
        if(i > j) return 0;
        if(i == j) return 1;
        if(m_[i][j] != -1)  return m_[i][j];
        if(s[i] == s[j]) m_[i][j] = dfs(s, i + 1, j - 1) + 2;
        else m_[i][j] = max(dfs(s, i, j - 1), dfs(s, i + 1, j));
        return m_[i][j];
    }

};
// @lc code=end

