/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /*unordered_map<int, int> mp;
        int res = -1;
        for(int i : nums){
             ++mp[i];
             if(mp[i] > 1){
                 res = mp[i];
                 break;
             }
        }
        return res;*/
        /*hash set solution, time O(n), space O(n)*/
        /*unordered_set<int> s;
        for(int i : nums){
            if(!s.insert(i).second) return i;
        }
        return -1;*/
        /*sort solution, time O(nlogn), space o(1), but mutate the orginal arrary*/
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i])
                return nums[i];
        }
        return -1;
    }
};
// @lc code=end

