/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target) return true;
            if(nums[l] < nums[mid]){
                if(nums[l] <= target && nums[mid] > target)
                    r = mid;
                else
                    l = mid + 1;
            }
            else if(nums[l] > nums[mid]){
                if(nums[mid] < target && target <= nums[r - 1])
                    l = mid + 1;
                else
                    r = mid;
            }
            else
                ++l;
        }
        return false;
    }
};
// @lc code=end

