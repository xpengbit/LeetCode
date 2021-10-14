/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int n = res.size();
            for(int j = 0; j < n; ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;        
    }
};

/*DFS/RECURSIVE Solution*/
/*class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;            
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(tmp);
            return;
        }
        //取当前元素
        tmp.push_back(nums[pos]);
        dfs(nums, pos + 1, tmp, res);
        tmp.pop_back();
        //不取当前元素
        dfs(nums, pos + 1, tmp, res);
    }

    void dfs2(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        res.push_back(tmp);
        for(int i = pos; i < nums.size(); ++i){
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};*/
// @lc code=end

