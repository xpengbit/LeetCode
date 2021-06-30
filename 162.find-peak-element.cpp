/*
 * @lc app=leetcode id=162 lang=cpp
 *
 * [162] Find Peak Element
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;

        int lo = 0, hi = n - 1;
        while (lo <= hi){
            int mid = lo + (hi - lo)/2;
            if((mid == 0 and nums[mid] > nums[mid + 1]) or (mid == n-1 and nums[mid] > nums[mid - 1]))
                return mid;
            else if(mid > 0 and nums[mid] > nums[mid-1] and mid < n-1 and nums[mid] > nums[mid+1])
                return mid;
            else if(mid < n - 1 and nums[mid] < nums[mid+1])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        return -1;
    }
};
// @lc code=end

