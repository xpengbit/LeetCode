/*
 * @lc app=leetcode id=532 lang=cpp
 *
 * [532] K-diff Pairs in an Array
 */

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //滑动窗口(双指针)
        /*if(nums.size() < 2) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, cnt = 0;
        while(j < n){
            j = i + 1;
            while(j < n && nums[j] < nums[i] + k) ++j;
            if(j < n && nums[j] == nums[i] + k)
                cnt++;
            i++;
            while(i < n && nums[i] == nums[i - 1]) ++i;
        }
        return cnt;*/
        
        int n = nums.size(), cnt = 0;
        if(nums.size() < 2) return 0;
        unordered_map<int, int> mp;
        for(int num : nums) ++mp[num];
        for(auto a : mp){
            if(k == 0 && a.second > 1) cnt++;
            if(k > 0 && mp.count(a.first + k)) cnt++;
        }
        return cnt;
    }
};
// @lc code=end

