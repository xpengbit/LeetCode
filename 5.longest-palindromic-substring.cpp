/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        /*if(s.empty()) return "";
        int n = s.length();
        int dp[n][n];
        memset(dp, 0, sizeof(dp));
        int left = 0, len = 1;
        for(int i = 0; i < n; i++){
            dp[i][i] = 1;
            for(int j = 0; j < i; j++){
                dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]));
                if(dp[j][i] && len < i - j + 1){
                    len = i - j + 1;
                    left = j;
                }
            }
        }
        return s.substr(left, len);*/

        /*no dp solution*/
        if(s.size() < 2) return s;
        int n = s.size(), maxLen = 0, start = 0;
        for(int i = 0; i < n; i++){
            if(n - i <= maxLen / 2) break; /*如果剩余的string还不到maxlen的一半，肯定也不会超过maxLen，退出*/
            int left = i, right = i;
            while(right < n - 1 && s[right] == s[right + 1]) ++right;  /*跳过相同的字符；例如noon，当left，right同时指向'o'*/
            while(left > 0 && right < n - 1 && s[right + 1] == s[left - 1]){
                right++; left--;
            }
            if(maxLen < right - left + 1){
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

