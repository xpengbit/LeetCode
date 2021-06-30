/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int hi = nums.size()-1, lo = 0;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == target) return true;
            
            if(nums[lo] < nums[mid] or nums[mid] > nums[hi]){
                if(target > nums[mid] or target < nums[lo])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            else if(nums[mid] < nums[hi] or nums[lo] > nums[mid]){
                if(target < nums[mid] or target > nums[hi])
                    hi = mid -1;
                else 
                    lo = mid + 1;
            }
            else
                hi--;
        }
        return false;    
    }
};
// @lc code=end

