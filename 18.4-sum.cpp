/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.empty() || nums.size() < 4) return {};
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int k = 0; k < n - 3; ++k){
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            for(int l = k + 1; l < n - 2; ++l){
                if(l > k + 1 && nums[l - 1] == nums[l]) continue;
                int i = l + 1, j = n -1;
                while(i < j){
                    long sum = (long)nums[k] + nums[l] + nums[i] + nums[j];
                    if(sum == target){
                        res.push_back({nums[k], nums[l], nums[i],nums[j]});
                        while(i < j && nums[i] == nums[i + 1]) ++i;
                        while(i < j && nums[j] == nums[j - 1]) --j;
                        ++i; --j;
                    }
                    else if(sum < target) ++i;
                    else --j;
                }
            }
        }
        return res;
    }
};
// @lc code=end

