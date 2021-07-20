/*
 * @lc app=leetcode id=931 lang=cpp
 *
 * [931] Minimum Falling Path Sum
 */

// @lc code=start
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int res = INT_MAX;
        if(m == 1){
            for(int i = 0; i < m; i++)
                res = min(res, matrix[0][i]);
            return res;
        }
        for(int i = 1; i < m; i++){
            for(int j = 0; j < m; j++){
                int pre = matrix[i - 1][j];
                if(j > 0) pre = min(pre, matrix[i -1][j - 1]);
                if(j + 1 < m) pre = min(pre, matrix[i - 1][j + 1]);
                matrix[i][j] += pre;
                if(i == m - 1)
                    res = min(res, matrix[i][j]);
            }
        }
        return res;
    }
};
// @lc code=end

