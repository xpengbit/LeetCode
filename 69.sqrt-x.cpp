/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;

        int lo = 1, hi = x/2;
        while(lo <= hi){
            long long int mid = lo + (hi - lo)/2;
            if(mid*mid <= x and (mid+1)*(mid+1) > x) return mid;
            else if(mid*mid > x) hi = mid - 1;
            else lo = mid + 1;
        }
        return lo;
    }
};
// @lc code=end

