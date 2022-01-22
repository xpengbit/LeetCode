/*
 * @lc app=leetcode id=1262 lang=cpp
 *
 * [1262] Greatest Sum Divisible by Three
 */

// @lc code=start
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(3);
        dp[0] = 0;
        dp[1] = INT_MIN;
        dp[2] = INT_MIN;
        for(int i = 0; i < n; ++i){
            int k = nums[i] % 3;
            auto dp_tmp = dp;
            for(int j = 0; j < 3; ++j){
                dp[j] = max(dp_tmp[j], dp_tmp[(j -  k + 3) % 3] + nums[i]);//取或者不取当前元素nums[i]
            }
        }
        return dp[0];
    }
};
// @lc code=end

