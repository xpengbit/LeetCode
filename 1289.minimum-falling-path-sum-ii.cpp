/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        //DP
        int m = arr.size();
        int n = arr[0].size();
        
        auto dp = vector<vector<int>>(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; ++j)
            dp[0][j] = arr[0][j];

        for(int i = 1; i < m; ++i){
            vector<pair<int, int>> tmp;
            for(int k = 0; k < n; ++k)
                tmp.push_back({dp[i - 1][k], k});
            sort(tmp.begin(), tmp.end());
            for(int j = 0; j < n; ++j){
                if(j == tmp[0].second)
                    dp[i][j] = tmp[1].first + arr[i][j];
                else
                    dp[i][j] = tmp[0].first + arr[i][j];
            }
        }
        
        int ret = INT_MAX;
        for(int j = 0; j < n; ++j)
            ret = min(ret, dp[m - 1][j]);

        return ret;
        
        
        /*int m = arr.size();
        int res = INT_MAX;
        if(m == 1){
            for(int i = 0; i < m; i++)
                res = min(res, arr[0][i]);
            return res;
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < m; j++){
                int preMin = INT_MAX;
                for(int k = 0; k < m; k++){
                    if(k != j)
                        preMin = min(preMin, arr[i - 1][k]);
                }
                arr[i][j] += preMin;
                if(i == m - 1)
                    res = min(res, arr[i][j]);
            }
        }
        return res;*/
    }
};
// @lc code=end

