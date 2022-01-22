/*
 * @lc app=leetcode id=754 lang=cpp
 *
 * [754] Reach a Number
 */

// @lc code=start
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int i = 0, sum = 0;
        while(!(sum >= target && (sum - target) % 2 == 0)){
            i++;
            sum += i;
        }
        return i;
    }
};
// @lc code=end

