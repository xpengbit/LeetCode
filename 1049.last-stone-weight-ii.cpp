/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        /*问题转化为把石头分两堆，差值最小
        a + b = sum, a - b = diff, 2*a = sum + diff
        a close to sum/2*/
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int target = sum >> 1;
        /*dp[i][j] 表示前i块石头组成的重量j*/
        vector<vector<int>> dp(stones.size() + 1, vector<int>(target + 1));
        for(int i = 1; i <= stones.size(); i++){
            for(int j = 1; j <= target; j++){
                dp[i][j] = dp[i - 1][j];
                if(j - stones[i - 1] >= 0) dp[i][j] = max(stones[i - 1] + dp[i - 1][j - stones[i - 1]], dp[i - 1][j]);
            }
        }
        return sum - 2 * dp[stones.size()][target];
    }
};
// @lc code=end

