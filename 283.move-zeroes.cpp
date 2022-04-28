/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while(j < nums.size()){
            if(nums[j] != 0)
                swap(nums[i++], nums[j]);
            j++;
        }
        return;
    }
};
// @lc code=end
//双指针。类似quick sort

