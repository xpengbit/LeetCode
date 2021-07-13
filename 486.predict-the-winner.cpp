/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 */

// @lc code=start
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        /*vector<vector<int>> memo(nums.size(), vector<int>(nums.size()));
        return dfs(nums, 0, nums.size() - 1, memo) >= 0;*/

        /*区间dp*/
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        for(int i = 0; i < n; i++) dp[i][i] = nums[i];
        for(int l = 1; l < n; l++){
            for(int i = 0; i < n - l; i++){
                int j = i + l;
                dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][n - 1] >= 0;
    }
private:
    int dfs(vector<int> nums, int i, int j, vector<vector<int>>& memo){
        if(i > j) return 0;
        if(memo[i][j] != NULL) return memo[i][j];
        memo[i][j] = max(nums[i] - dfs(nums, i + 1, j, memo), nums[j] - dfs(nums, i, j - 1, memo));
        return memo[i][j];
    }
};
// @lc code=end

