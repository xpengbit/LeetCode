/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> visited(nums.size(), 0), out;
        dfs(nums, out, visited, res);
        return res;    
    }
private:
    void dfs(vector<int>& nums, vector<int>& out, vector<int>& visited, vector<vector<int>>& res){
        if(out.size() == nums.size()){
            res.push_back(out);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1) continue;
            visited[i] = 1;
            out.push_back(nums[i]);
            dfs(nums, out, visited, res);
            out.pop_back();
            visited[i] = 0;
        }
    }
};
// @lc code=end

