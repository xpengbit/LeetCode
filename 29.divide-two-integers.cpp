/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

// @lc code=start
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN and divisor == -1) return INT_MAX;
        bool isNegative = (dividend > 0 and divisor < 0) or (dividend < 0 and divisor > 0);
        long long a = labs(dividend), b = labs(divisor), res = 0;
        if(b == 1) return isNegative ? -a : a;
        while(a >= b){
            long c = b, count = 1;
            while(a >= (c << 1)){
                c <<= 1;
                count <<= 1;
            }
            a -= c;
            res += count;
        }

        return isNegative ? -res : res;
    }
};
// @lc code=end

