/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n, 1);
        int res = 0;
        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            res = max(res, dp[i]);
        }
        return res;
        /*const int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        vector<int> dp(n, 1);
        int maxLen = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            if(dp[i] > maxLen)
                maxLen = dp[i];
        }
        return maxLen;*/
    }
};
// @lc code=end

