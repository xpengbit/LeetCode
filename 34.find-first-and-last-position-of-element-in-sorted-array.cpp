/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        if(nums.size() == 0) return res;
        if(nums[0] > target) return res;

        int lo = 0, hi = nums.size()-1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                res[0] = mid;
                hi = mid -1;
            }
            else if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        lo = 0;
        hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(nums[mid] == target){
                res[1] = mid;
                lo = mid + 1;
            }
            else if(nums[mid] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        } 
        
        return res;
    }
};
// @lc code=end

