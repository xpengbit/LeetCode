/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> comb;
        dfs(res, comb, n, k, 1);
        return res;   
    }
private:
    void dfs(vector<vector<int>>& res, vector<int>& comb, int n, int k, int pos){
        if(comb.size() == k){
            res.push_back(comb);
            return;
        }
        for(int i = pos; i <= n; i++){
            comb.push_back(i);
            dfs(res, comb, n, k, i + 1);
            comb.pop_back();
        }
    }
};
// @lc code=end

