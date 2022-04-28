/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        /*unordered_map<int, int> mp;
        mp[0] = 1;  //前缀和正好等于k
        int prefixSum = 0, res = 0;
        for(int n : nums){
            prefixSum += n;
            if(mp.count(prefixSum - k))
                res += mp[prefixSum - k];
            mp[prefixSum]++;
        }
        return res;*/

        unordered_map<int, int> Map;
        Map[0] = 1;
        int res = 0, preSum = 0;
        for(int x : nums){
            preSum += x;
            if(Map.count(preSum - k)) res += Map[preSum - k];
            Map[preSum]++;
        }

        return res;
    }
};
// @lc code=end

