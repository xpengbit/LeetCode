/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        int res = -1;
        for(int i : nums){
             ++mp[i];
             if(mp[i] > 1){
                 res = mp[i];
                 break;
             }
        }
        return res;
    }
};
// @lc code=end

