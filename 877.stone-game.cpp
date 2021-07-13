/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 */

// @lc code=start
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        /*int n = piles.size();
        memo = vector<vector<int>>(n, vector<int>(n, INT_MIN));
        int res = helper(piles, 0, n - 1);
        return memo[0][n - 1] > 0;*/

        /*dp solution*/
        int n  = piles.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int i = 0; i < n; i++) dp[i][i] = piles[i];
        for(int l = 1; l < n; l++){
            for(int i = 0; i < n - l; i++){
                int j = i + l;
                dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] > 0;    
    }
private:
    vector<vector<int>> memo;

    int helper(vector<int>& piles, int i, int j){
        if(i == j) return piles[i];
        if(memo[i][j] != INT_MIN) return memo[i][j];
        memo[i][j] = max(piles[i] - helper(piles, i + 1, j), piles[j] - helper(piles, i, j - 1));
        return memo[i][j];
    }
};
// @lc code=end

