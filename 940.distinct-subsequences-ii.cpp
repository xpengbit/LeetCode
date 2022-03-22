/*
 * @lc app=leetcode id=940 lang=cpp
 *
 * [940] Distinct Subsequences II
 */

// @lc code=start
class Solution {
    long dp[2005]; //dp[i]表示 1-i 之间distinct subsequence 的数量。
    long M = 1e9 + 7;
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        s = "#" + s;
        vector<int> last(26, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; ++i){
            int j = last[s[i] - 'a'];
            dp[i] = 2 * dp[i - 1] % M - (j >= 1 ? dp[j - 1] : 0);
            dp[i] = (dp[i] + M) % M;
            last[s[i] - 'a'] = i;
        }
        return dp[n] - 1; //去掉 NUll
    }
};
// @lc code=end

