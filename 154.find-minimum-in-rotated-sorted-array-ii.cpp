/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];

        int lo = 0, hi = n-1;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;

            if(nums[hi] < nums[mid]) lo = mid + 1;
            else if(nums[0] > nums[mid]) hi = mid;
            else hi--;
        }
        return nums[lo];    
    }
};
// @lc code=end

