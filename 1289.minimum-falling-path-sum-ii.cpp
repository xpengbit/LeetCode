/*
 * @lc app=leetcode id=1289 lang=cpp
 *
 * [1289] Minimum Falling Path Sum II
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int m = arr.size();
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
        return res;
    }
};
// @lc code=end

