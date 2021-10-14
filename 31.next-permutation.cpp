/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty() || nums.size() < 2) return;
        int n = nums.size(), i, j;
        for(i = n - 2; i >= 0; --i){
            if(nums[i] < nums[i + 1]){
                for(j = n - 1; j > i; --j){
                    if(nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};
// @lc code=end

