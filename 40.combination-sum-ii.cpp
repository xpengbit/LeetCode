/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, out, res);
        return res;            
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res){
        if(target < 0) return;
        if(target == 0){
            res.push_back(out); return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i - 1] == candidates[i]) continue;
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, out, res);
            out.pop_back();
        }
    }
};
// @lc code=end

