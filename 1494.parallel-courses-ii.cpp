/*
 * @lc app=leetcode id=1494 lang=cpp
 *
 * [1494] Parallel Courses II
 */

// @lc code=start
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> dp(1 << n, INT_MAX / 2); // dp[state] 表示到达state状态需要几轮。
        vector<int> preState(1 << n, 0);
        vector<int> preCourse(n, 0);

        for(auto x : relations)
            preCourse[x[1] - 1] |= 1 << (x[0] - 1);
        
        for(int state = 0; state < (1 << n); ++state){
            preState[state] = 0;
            for(int i = 0; i < n; ++i){
                if((state >> i) & 1)
                    preState[state] |= preCourse[i];
            }
            if(preState[state] == 0 && __builtin_popcount(state) <= k)
                dp[state] = 1;
        }

        dp[0] = 0;
        for(int state = 1; state < (1 << n); ++state){
            for(int subset = state; subset > 0; subset = (subset - 1) & state){
                if(__builtin_popcount(state) - __builtin_popcount(subset) <= k && (preState[state] & subset) == preState[state])
                    dp[state] = min(dp[state], dp[subset] + 1);
            }
        }
        return dp[(1 << n) - 1];
    }
};
// @lc code=end

//这道题使用状态压缩dp。

