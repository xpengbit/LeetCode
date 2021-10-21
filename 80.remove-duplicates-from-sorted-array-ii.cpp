/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, n = nums.size();
        for(int i = 0; i < n; ++i){
            if(i > 0 && i < n - 1 && nums[i] == nums[i - 1] && nums[i] == nums[i + 1])
                continue;
            nums[index++] = nums[i];
        }
        return index;
    }
};
// @lc code=end

