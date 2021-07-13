/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=starm
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        for(int i = 0; i <= m; i++) dp[i][0] = 1;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i -1][j] + dp[i - 1][j -1];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[m][n];
        
        /*memorization + recursion solution*/
        /*m_ = vector<vector<unsigned long long>>(m, vector<unsigned long long>(n, -1));
        return numDistinct(0, 0, s, t);*/
    }
private:
    vector<vector<unsigned long long>> m_;
    int numDistinct(int i, int j, string s, string t){
        if(j >= t.length()) return 1; /*t string 为空*/
        if(i >= s.length()) return 0;
        if(m_[i][j] != -1) return m_[i][j];

        int subseq = numDistinct(i + 1, j, s, t);
        if(s[i] == t[j])
            subseq += numDistinct(i + 1, j + 1, s, t);
        return m_[i][j] = subseq;
    }

};
// @lc code=end

