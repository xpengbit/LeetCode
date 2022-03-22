/*
 * @lc app=leetcode id=514 lang=cpp
 *
 * [514] Freedom Trail
 */

// @lc code=start
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> letter2pos;
        for(int i = 0; i < ring.size(); ++i){
            letter2pos[ring[i]].push_back(i);
        }

        int n = key.size();
        int m = ring.size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX/2));

        for(int cur_pos : letter2pos[key[0]])
            dp[0][cur_pos] = min(cur_pos, m - cur_pos);

        for(int i = 1; i < n; ++i){
            for(int cur_pos : letter2pos[key[i]]){
                for(int pre_pos : letter2pos[key[i - 1]]){
                    dp[i][cur_pos] = min(dp[i][cur_pos], dp[i - 1][pre_pos] + min(abs(cur_pos - pre_pos), m - abs(cur_pos - pre_pos)));
                }
            }
        }

        int ret = INT_MAX;
        for(int pos : letter2pos[key[n - 1]])
            ret = min(ret, dp[n - 1][pos]);
        
        return ret + n;
    }
};
// @lc code=end

