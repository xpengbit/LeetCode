/*
 * @lc app=leetcode id=220 lang=cpp
 *
 * [220] Contains Duplicate III
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        map<long, int> mp;
        int j = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(i - j > k) mp.erase(nums[j++]);
            auto it = mp.lower_bound((long)nums[i] - t);
            if(it != mp.end() && (it->first - nums[i]) <= t) return true;
            mp[nums[i]] = i;
        }
        return false;    
    }
};
// @lc code=end

