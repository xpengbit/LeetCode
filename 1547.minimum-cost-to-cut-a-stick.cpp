/*
 * @lc app=leetcode id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        N = n;
        m = cuts.size();
        std::sort(cuts.begin(), cuts.end());
        memo = vector<vector<int>>(m + 1, vector<int>(m + 1, -1));
        return dfs(cuts, 0, m);
    }
private:
    vector<vector<int>> memo;
    int N, m;

    int dfs(vector<int>& cuts, int left, int right){
        if(memo[left][right] != -1) return memo[left][right];
        if(left >= right) return 0;
        int cost = (right == m ? N : cuts[right]) - (left == 0 ? 0 : cuts[left - 1]);
        memo[left][right] = INT_MAX;
        for(int i = left; i < right; i++){
            memo[left][right] = min(memo[left][right], dfs(cuts, left, i) + dfs(cuts, i + 1, right) + cost);
        }
        return memo[left][right];
    }
};
// @lc code=end

