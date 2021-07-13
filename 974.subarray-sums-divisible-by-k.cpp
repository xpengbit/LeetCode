/*
 * @lc app=leetcode id=974 lang=cpp
 *
 * [974] Subarray Sums Divisible by K
 */

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefixSum = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for(int num : nums){
            prefixSum = (prefixSum + num % k + k) % k;
            cout << "prefixSum =" << prefixSum;
            if(mp.count(prefixSum)) res += mp[prefixSum];
            ++mp[prefixSum];
        }
        return res;
    }
};
// @lc code=end

