/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        /*int res;
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2,0));
        for(int i = 1; i <= nums.size(); i++){
            /*0 表示不抢， 1表示抢*/
        /*    dp[i][0] = max(dp[i -1][0], dp[i - 1][1]);
            dp[i][1] = nums[i - 1] + dp[i - 1][0];  /*nums[i -1] 是因为dp从1开始，对应到数组是i-1*/
        /*}
        return max(dp[nums.size()][0], dp[nums.size()][1]);*/

        vector<int> dp(nums.size() + 1);
        dp[0] = 0;
        dp[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i -1]); /*第i-1间抢了，第i
            间就不能抢， 第i-1没抢，第i间可抢可不抢*/
        }
        return dp[nums.size()];
    }
};
// @lc code=end

