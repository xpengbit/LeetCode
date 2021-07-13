/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) dp[i][0] = i;
        for(int j = 1; j <= n; j++) dp[0][j] = j;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(word1[i - 1] == word2[j -1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
            }
        }
        return dp[m][n];

        /*recursion + memorization*/
        /*memo = vector<vector<int>>(m + 1, vector<int>(n + 1, INT_MIN));
        return helper(word1, 0, word2, 0); */       
    }
private:
    vector<vector<int>> memo;
    int helper(string word1, int l1, string word2, int l2){
        if(l1 == word1.length()) return word2.length() - l2;
        if(l2 == word2.length()) return word1.length() - l1;
        if(memo[l1][l2] != INT_MIN) return memo[l1][l2];
        if(word1[l1] == word2[l2])
            memo[l1][l2] = helper(word1, l1 + 1, word2, l2 + 1);
        else{
            int replaceVal = helper(word1, l1 + 1, word2, l2 + 1) + 1;
            int delVal = helper(word1, l1 + 1, word2, l2) + 1;
            int insertVal = helper(word1, l1, word2, l2 + 1) + 1;
            memo[l1][l2] = min(replaceVal, min(delVal, insertVal));
        }
        return memo[l1][l2];
    }
};
// @lc code=end

