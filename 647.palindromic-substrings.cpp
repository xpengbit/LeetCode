/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        int res = 0;
        /*dp[i][j] 为i，j之间的回文数量*/
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i ; j < n; j++){
                dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
                if(dp[i][j]) res++;
            }
        }
        return res;
    }
};
// @lc code=end

