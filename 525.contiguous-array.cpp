/*
 * @lc app=leetcode id=525 lang=cpp
 *
 * [525] Contiguous Array
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*n2 solution 会超时*/
        /*if(nums.size() == 0) return 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            int zeroNum = 0, oneNum = 0;
            for(int j = i ; j < nums.size(); j ++){
                if(nums[j] == 0) zeroNum++;
                else oneNum++;
                if(zeroNum == oneNum)
                    res = max(res, j - i + 1);
            }
        }
        return res;*/
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == 0) nums[i] = -1;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefixSum = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(mp.count(prefixSum))
                res = max(res, i - mp[prefixSum]);
            else
                mp[prefixSum] = i;
        }
        return res;
    }
};
// @lc code=end

