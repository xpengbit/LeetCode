/*
 * @lc app=leetcode id=1590 lang=cpp
 *
 * [1590] Make Sum Divisible by P
 */

// @lc code=start
using ll = long long;
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0ll);
        sum = sum % p;
        ll t0 = sum % p;
        if(t0 == 0) return 0;

        unordered_map<int, int> m;
        m[0] = -1;
        ll preSum = 0;
        int ret = INT_MAX;
        for(int i = 0; i < n; ++i){
            preSum += nums[i];
            preSum = preSum % p;
            if(m.find((preSum % p - t0 + p) % p) != m.end()){
                int j = m[(preSum % p - t0 + p) % p];
                ret = min(ret, i - j);
            }
            m[preSum % p] = i;
        }

        return ret >= n ? -1 : ret;
    }
};
// @lc code=end


