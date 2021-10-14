/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3 || nums.empty()) return 0;
        int closest = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size() - 2; ++k){
            //if(nums[k] * 3 > target) return min(closest, nums[k] + nums[k + 1] + nums[k + 2]);
            int i = k + 1, j = nums.size() - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                int newdiff = abs(sum - target);
                if(newdiff < diff){
                    diff = newdiff;
                    closest = sum;
                }
                if(sum < target) i++;
                else j--;
            }
        }
        return closest;
    }
};
// @lc code=end

