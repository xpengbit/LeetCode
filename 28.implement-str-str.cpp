/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        /*if(needle.empty()) return 0;
        const int m = haystack.size(), n = needle.size();
        if(m < n) return -1;
        for(int i = 0; i <= m - n; ++i){
            int j = 0;
            for(; j < n; ++j){
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1;*/

        //KMP
        if(needle.empty()) return 0;
        string s = haystack, p = needle;
        int m = s.size(), n = p.size();
        if(m < n) return -1;
        vector<int> dp(m);
        dp[0] = (s[0] == p[0]);
        if(n == 1 && dp[0] == 1) return 0;

        vector<int> suffix = preprocess(p);
        for(int i = 1; i < m; ++i){
            int j = dp[i - 1];
            while(j > 0 && s[i] != p[j])
                j = suffix[j - 1];
            dp[i] = j + (s[i] == p[j]);

            if(dp[i] == n)
                return i - n + 1;
        }
        return -1;
    }

    vector<int> preprocess(string s){
        int n = s.size();
        vector<int> dp(n);
        dp[0] = 0;
        for(int i = 1; i < n; ++i){
            int j = dp[i - 1];
            while(j > 0 && s[i] != s[j])
                j = dp[j - 1];
            dp[i] = j + (s[i] == s[j]); 
        }
        return dp;
    }
};
// @lc code=end

