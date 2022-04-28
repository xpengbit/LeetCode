/*
 * @lc app=leetcode id=930 lang=cpp
 *
 * [930] Binary Subarrays With Sum
 */

// @lc code=start
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ret = 0, preSum = 0;
        unordered_map<int, int> m;
        m[0] = 1;
        for(int i = 0; i < n; ++i){
            preSum += nums[i];
            if(m.find(preSum - goal) != m.end())
                ret += m[preSum - goal];
            m[preSum]++;
        }
        return ret;
    }
};
// @lc code=end

