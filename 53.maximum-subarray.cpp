/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*Kadane's Algorithm*/
        /*int res = INT_MIN;
        int sumEnd = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            sumEnd = sumEnd + nums[i];
            res = max(res, sumEnd);
            if(sumEnd < 0) sumEnd = 0;
        }
        return res;*/

        /*Greedy Solution*/
        int res = INT_MIN;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = max(sum + nums[i], nums[i]);
            res = max(res, sum);
        }
        return res;
    }
};
// @lc code=end

