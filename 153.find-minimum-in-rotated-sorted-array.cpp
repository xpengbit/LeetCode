/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];
        
        int lo = 0, hi = n-1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(mid > 0 and nums[mid] < nums[mid-1]) return nums[mid];
            if(nums[mid] > nums[mid+1]) return nums[mid+1];

            if(nums[lo] < nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return nums[lo];    
    }
};
// @lc code=end

