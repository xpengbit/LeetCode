/*
 * @lc app=leetcode id=1685 lang=cpp
 *
 * [1685] Sum of Absolute Differences in a Sorted Array
 */

// @lc code=start
class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        vector<int> ret(n);
        for(int i = 0; i < n; ++i)
            sum += (nums[i] - nums[0]);
        ret[0] = sum;

        for(int i = 1; i < n; ++i){
            ret[i] = ret[i - 1] + (nums[i] - nums[i - 1])*i - (nums[i] - nums[i - 1]) * (n - i);
        }

        return ret;   
    }
};
// @lc code=end

