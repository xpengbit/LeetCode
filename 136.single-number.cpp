/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*使用异或。只要是偶数次，都可以清零*/
        int x = 0;
        for(auto num : nums)
            x ^= num;
        return x;

        /*return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());*/
    }
};
// @lc code=end

