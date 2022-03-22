/*
 * @lc app=leetcode id=740 lang=cpp
 *
 * [740] Delete and Earn
 */

// @lc code=start
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int M = *max_element(nums.begin(), nums.end());
        vector<int> gain(M + 1);
        for(int x : nums)
            gain[x] += x;
        vector<int> dp(M + 1); //dp[i] 表示截至到i的最大收益
        dp[0] = 0; dp[1] = gain[1];
        for(int i = 2; i <= M; ++i){
            dp[i] = max(dp[i - 2] + gain[i], dp[i - 1]);
        }  
        return dp[M];
    }
};
// @lc code=end

//这个题本质上跟House robber类似。
//看到题目里的maxmum number of points 应该想到dp.
//这个题包装的有点不太像dp。没有遍历nums的index， 而是遍历nums中的值，从0--M
//gain[x] 由x在nums中出现的次数得出。