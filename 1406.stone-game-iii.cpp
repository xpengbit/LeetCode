/*
 * @lc app=leetcode id=1406 lang=cpp
 *
 * [1406] Stone Game III
 */

// @lc code=start
class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        memo = vector<int>(n, INT_MIN);
        int res = helper(stoneValue, 0);
        if(res == 0) return "Tie";
        else if(res > 0) return "Alice";
        else return "Bob";
    }
private:
    vector<int> memo;
    int helper(vector<int>& stoneValue, int index){
        if(index >= stoneValue.size()) return 0;
        if(memo[index] != INT_MIN) return memo[index];
        int sum = 0;
        int res = INT_MIN;
        for(int i = index; i < index + 3 && i < stoneValue.size(); i++){
            sum += stoneValue[i];
            res = max(res, sum - helper(stoneValue, i + 1));
        }
        return memo[index] = res;
    }
};
// @lc code=end

