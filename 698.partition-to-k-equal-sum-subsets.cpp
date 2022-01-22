/*
 * @lc app=leetcode id=698 lang=cpp
 *
 * [698] Partition to K Equal Sum Subsets
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        vector<int> sub(k, 0);
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sub, 0, sum / k);
    }

    bool dfs(vector<int>& nums, vector<int>& sub, int index, int target){
        if(index == nums.size()){
            bool res = true;
            for(int s : sub)
                res = (res && s == target);
            return res;
        }
        
        for(int i = 0; i < sub.size(); ++i){
            if(sub[i] + nums[index] > target) continue;
            sub[i] += nums[index];
            if(dfs(nums, sub, index + 1, target)) return true;
            sub[i] -= nums[index];
        }
        return false;
    }
};
// @lc code=end

