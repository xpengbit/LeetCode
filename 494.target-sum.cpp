/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*a + b = s, a - b = target; a = (s + target)/2*/
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target || (sum + target) % 2 != 0) return 0;
        return helper2(nums, (sum + target) / 2);
    }
private:
    int helper2(vector<int>& nums, int sum){
        /*dp[i] sum为i的方法数*/
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for(int num : nums){
            for(int j = sum; j >= num; j--){
                dp[j] += dp[j - num];
            }
        }
        return dp[sum];
    }
    int helper(vector<int>& nums, int sum){
        /*dp[i][j], i个数字中和为j的方法数*/
        vector<vector<int>> dp(nums.size() + 1, vector<int>(sum + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= nums.size(); i++){
            for(int j = 0; j <= sum; j++){
                dp[i][j] = dp[i - 1][j];
                if(j >= nums[i - 1]) dp[i][j] += dp[i - 1][j - nums[i - 1]];
            }
        }
        return dp[nums.size()][sum];
    }
};
// @lc code=end

