/*
 * @lc app=leetcode id=278 lang=cpp
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 0, hi = n;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(isBadVersion(mid)) hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};
// @lc code=end

