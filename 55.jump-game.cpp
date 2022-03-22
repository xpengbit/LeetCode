/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        //dp 解法
        /*int n = nums.size();
        vector<int> dp(n, 0); //dp[i]表示在位置i的跳力
        dp[0] = 0;
        for(int i = 1; i < n; ++i){
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;*/
        int n = nums.size(), maxReach = 0;
        for(int i = 0; i < n; ++i){
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end

