/*
 * @lc app=leetcode id=1201 lang=cpp
 *
 * [1201] Ugly Number III
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int left = 0, right = 2e9;
        while(left < right){
            int mid = left + (right - left) / 2;
            int cnt = mid / a + mid / b + mid / c - mid / lcm(a, b) - mid / lcm(b, c) - mid / lcm(a, c) + mid / lcm(a, lcm(b, c));
            if(cnt < n) left = mid + 1;
            else right = mid;
        }
        return left;
    }
    long gcd(long a, long b){
        return a == 0 ? b : gcd(b % a, a);
    }
    long lcm(long a, long b){
        return a * b / gcd(a, b);
    }
};
// @lc code=end

