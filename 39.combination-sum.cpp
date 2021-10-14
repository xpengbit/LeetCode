/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(candidates, target, 0, out, res);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res){
        if(target < 0) return;
        if(target == 0){
            res.push_back(out);
            return;
        }
        for(int i = start; i < candidates.size(); ++i){
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

