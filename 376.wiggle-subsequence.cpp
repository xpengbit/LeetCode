/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.empty()) return 0;
        size_t n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        /*dp[i][0] 表示在第i个递减wiggle subsequence 长度。dp[i][1]表示第i个递增*/
        dp[0][0] = 1; dp[0][1] = 1;
        for(int i = 1; i < n; ++i){
            if(nums[i] < nums[i - 1]){
                dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
                dp[i][1] = dp[i - 1][1];
            }
            else if(nums[i] > nums[i - 1]){
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][1]);
            }
            else{
                dp[i][1] = dp[i - 1][1];
                dp[i][0] = dp[i - 1][0];
            }
        }
        return max(dp[n - 1][0], dp[n - 1][1]); 
    }
};
// @lc code=end

