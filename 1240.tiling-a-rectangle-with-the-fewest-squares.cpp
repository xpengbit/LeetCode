/*
 * @lc app=leetcode id=1240 lang=cpp
 *
 * [1240] Tiling a Rectangle with the Fewest Squares
 */

// @lc code=start
class Solution {
public:
    int tilingRectangle(int n, int m) {
        if(n > m) return tilingRectangle(m, n);
        vector<vector<int>> memo(n + 1, vector<int>(m + 1));
        return helper(n, m, memo);    
    }
private:
    int helper(int n, int m, vector<vector<int>>& memo){
        if(n > m) return helper(m, n, memo);
        if(n == 0) return 0;
        if(n == m) return 1;
        if(n == 1) return m;
        if(memo[n][m] > 0) return memo[n][m];
        int res = INT_MAX;
        for(int i = 1; i <= n; ++i){
            res = min(res, 1 + helper(n - i, m, memo) + helper(i, m - i, memo));
            res = min(res, 1 + helper(i, n - i, memo) + helper(m - i, n, memo));
            for(int j = n - i + 1; j < m - i && j < n; ++j){
                res = min(res, 2 + helper(n - i, m - j, memo) + helper(i + j -n, m - i - j, memo) + helper(n - j, m - i, memo));
            }
        }
        return memo[n][m] = res;
    }
};
// @lc code=end

