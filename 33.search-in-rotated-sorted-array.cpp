/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size()-1;
        int lo = 0;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return mid;
            if(nums[lo] <= nums[mid]){
                if(target > nums[mid] or target < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else{
                if(target > nums[hi] or target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

