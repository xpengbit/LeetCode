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
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long res = 0;
        int shift = 31;
        
        while(a >= b){
            while(a < (b << shift)){
                shift--;
            }
            a -= b << shift;
            res += 1 << shift;
        }

        return isNegative ? -res : res;
    }
};
// @lc code=end

