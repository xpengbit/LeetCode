/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            /判断整数溢出的方法/
            if(abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10; 
        }
        return res;
    }
};
// @lc code=end

