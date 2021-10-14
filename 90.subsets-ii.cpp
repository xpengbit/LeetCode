/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        /*vector<vector<int>> res(1);
        int size = 1, pre = nums[0];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            if(pre != nums[i]){
                pre = nums[i];
                size = res.size();
            }
            int newSize = res.size();
            for(int j = newSize - size; j < res.size(); ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }    
        return res;*/
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(nums, 0, tmp, res);
        return res;
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        res.push_back(tmp);
        for(int i = pos; i < nums.size(); ++i){
            if(i > pos && nums[i - 1] == nums[i]) continue;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};
// @lc code=end

