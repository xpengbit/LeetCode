/*
 * @lc app=leetcode id=473 lang=cpp
 *
 * [473] Matchsticks to Square
 */

// @lc code=start
class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        vector<int> edgeSum(4, 0);
        if(sum % 4 != 0) return false;
        return dfs(matchsticks, edgeSum, 0, sum / 4);    
    }

    bool dfs(vector<int>& matchsticks, vector<int>& edgeSum, int index, int target){
        if(index == matchsticks.size())
            return edgeSum[0] == target && edgeSum[1] == target && edgeSum[2] == target;

        for(int i = 0; i < 4; ++i){
            if(edgeSum[i] + matchsticks[index] > target) continue;
            edgeSum[i] += matchsticks[index];
            if(dfs(matchsticks, edgeSum, index + 1, target)) return true;
            edgeSum[i] -= matchsticks[index];
        }
        return false;
    }
};
// @lc code=end

