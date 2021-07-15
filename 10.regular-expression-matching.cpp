/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        /*if(p.empty()) return s.empty();
        bool isFirstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if(p.length() >= 2 && p[1] == '*'){
            bool starMatchNull = isMatch(s, p.substr(2));
            bool starMatchStr = isFirstMatch && isMatch(s.substr(1), p);
            return starMatchNull || starMatchStr;
        }
        else
            return isFirstMatch && isMatch(s.substr(1), p.substr(1));*/
        
        /*DP Solution*/
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if( j > 1 && p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (p[j - 2] == s[i - 1] || p[j - 2] =='.') && dp[i - 1][j]);
                else
                    dp[i][j] = i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
            }
        }
        return dp[m][n];
        /*recursion + memorization*/    
        /*memo = vector<vector<int>>(s.length() + 1, vector<int>(p.length() + 1, -1));
        return helper(s, 0, p, 0);*/
    }
private:
    vector<vector<int>> memo;
    bool helper(string s, int l1, string p, int l2){
        if(memo[l1][l2] != -1) return memo[l1][l2];
        bool res;
        if(l2 == p.length()) return l1 == s.length();
        else{
            bool isFirstMatch = l1 < s.length() && (s[l1] == p[l2] || p[l2] == '.');
            if(l2 + 1 < p.length() && p[l2 + 1] == '*'){
                bool starMatchNull = helper(s, l1, p, l2 + 2);
                bool starMatchStr = isFirstMatch && helper(s, l1 + 1, p, l2);
                res = starMatchNull || starMatchStr;
            }
            else
                res = isFirstMatch && helper(s, l1 + 1, p, l2 + 1);
        }
        return memo[l1][l2] = res;
    }
};
// @lc code=end

