/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        //KMP
        int n = s.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for(int i = 1; i < n; ++i){
            int j = dp[i - 1];
            while(j > 0 && s[i] != s[j])
                j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]);
        }
        int k = dp[n - 1];
        return (k > 0 && (n % (n - k) == 0));    
    }
};
// @lc code=end

