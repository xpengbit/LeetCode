/*
 * @lc app=leetcode id=523 lang=cpp
 *
 * [523] Continuous Subarray Sum
 */

// @lc code=start
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefixSum = 0;
        mp[0] = - 1;  //map 里存的是余数跟位置index的映射
        for(int i = 0; i < nums.size(); i++){
            prefixSum = (prefixSum + nums[i]) % k;
            if(mp.count(prefixSum)){
                if((i - mp[prefixSum]) > 1) return true;
            }
            else
                mp[prefixSum] = i;
        }
        return false;
    }
};
// @lc code=end

