/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < 32; ++i){
            int sum = 0;
            for(int num : nums){
                /*把数组里每一个数字的每一位相加，如果出现了3次，模3为0，不为0的部分就是出现1次的数字*/
                sum += (num >> i) & 1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};
// @lc code=end

