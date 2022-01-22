/*
 * @lc app=leetcode id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

// @lc code=start
class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs[0].size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(checkLarger(j, i, strs))
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int ret = 0;
        for(int i = 0; i < n; ++i)
            ret = max(ret, dp[i]);
        
        return n - ret;
    }

    bool checkLarger(int a, int b, vector<string>& s){
        int m = s.size();
        for(int i = 0; i < m; ++i){
            if(s[i][a] > s[i][b])
                return false;
        }
        return true;
    }
};
// @lc code=end

