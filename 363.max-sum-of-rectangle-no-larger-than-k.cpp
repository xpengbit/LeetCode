/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return 0;
        int res = INT_MIN, m = matrix.size(), n = matrix[0].size();

        for(int i = 0; i < n; ++i){
            vector<int> sum(m, 0);
            for(int j = i; j < n; ++j){
                for(int k = 0; k < m; ++k){
                    sum[k] += matrix[k][j];
                }

                int curSum = 0;
                set<int> s({0});
                for(auto a : sum){
                    curSum += a;
                    auto it = s.lower_bound(curSum - k);
                    if(it != s.end()) res = max(res, curSum - *it);
                    s.insert(curSum);
                }
            }
        }
        return res;
    }
};
// @lc code=end

