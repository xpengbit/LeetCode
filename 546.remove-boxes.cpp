/*
 * @lc app=leetcode id=546 lang=cpp
 *
 * [546] Remove Boxes
 */

// @lc code=start
class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        //Top-Down, Recursive + memory
        /*int n = boxes.size();
        int dp[100][100][100] = {0};
        return helper(boxes, 0, n - 1, 0, dp);*/

        //Bottom-Up
        int n = boxes.size();
        int dp[100][100][100] = {0};

        for(int i = 0; i < n; ++i){
            for(int k = 0; k <= i; ++k)
                dp[i][i][k] = (k + 1) * (k + 1);
        }

        for(int l = 1; l < n; ++l){
            for(int j = l; j < n; ++j){
                int i = j - l;
                for(int k = 0; k <= i; ++k){
                    int res = (k + 1) * (k + 1) + dp[i + 1][j][0];
                    for(int m = i + 1; m <= j; ++m){
                        if(boxes[m] == boxes[i])
                            res = max(res, dp[i + 1][m - 1][0] + dp[m][j][k + 1]);
                    }
                    dp[i][j][k] = res;
                }
            }
        }

        return n == 0 ? 0 : dp[0][n - 1][0];    
    }
    
    //Top-Down, Recursive + memory
    int helper(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]){
        if(i > j) return 0;
        if(dp[i][j][k] > 0) return dp[i][j][k];
        
        int k0 = k, i0 = i;
        for(; i + 1 <= j && boxes[i] == boxes[i + 1]; ++i, ++k);
        int res = (k + 1) * (k + 1) + helper(boxes, i + 1, j, 0, dp);

        for(int m = i + 1; m <= j; ++m){
            if(boxes[m] == boxes[i])
                res = max(res, helper(boxes, i + 1, m - 1, 0, dp) + helper(boxes, m, j, k + 1, dp));
        }

        return dp[i0][j][k0] = res;
    }
};
// @lc code=end

