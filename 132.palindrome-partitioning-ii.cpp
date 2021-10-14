/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        /*这个题用到了两个dp的数组。dp[i]表示[0,i]范围内字串最小分割数。在这个区间内用j遍历每一个位置
        [0,j-1],[j,i] 假设我们已经知道[0,j-1]的分割数dp[j - 1], 然后判断[j, i]是否为回文，如果是的话，dp[i] = 1 + dp[j - 1]
        二维dp数组p[i][j]表示i-j范围内的子串是否为回文串*/
        vector<vector<bool>> p(n, vector<bool>(n));
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            dp[i] = i;
            for(int j = 0; j <= i; j++){
                if(s[i] == s[j] && (i - j < 2 || p[j + 1][i - 1])){
                    p[j][i] = true;
                    dp[i] = j == 0 ? 0 : min(dp[i], dp[j - 1] + 1);
                }
            }
        }
        return dp[n - 1];
    }
};
// @lc code=end

