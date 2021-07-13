/*
 * @lc app=leetcode id=1140 lang=cpp
 *
 * [1140] Stone Game II
 */

// @lc code=start
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        memo = vector<vector<int>>(n, vector<int>(2*n, INT_MIN));
        vector<int> sum(n);
        for(int i = n - 1; i >=0; i--){
            if(i == n - 1) sum[i] = piles[i];
            else sum[i] = piles[i] + sum[i + 1];
        }
        return helper(piles, 0, 1, sum);
    }
private:
    vector<vector<int>> memo;

    int helper(vector<int>& piles, int index, int M, vector<int>& sum){
        if(index == piles.size()) return 0;
        if((piles.size() - index) <= 2*M) return sum[index];
        if(memo[index][M] != INT_MIN) return memo[index][M];
        int min_val = INT_MAX;
        for(int i = 1; i <= 2*M; i++){
            min_val = min(min_val, helper(piles, index + i, max(i, M), sum));
        }
        return memo[index][M] = sum[index] - min_val;
    }
};
// @lc code=end

