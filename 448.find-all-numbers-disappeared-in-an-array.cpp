/*
 * @lc app=leetcode id=448 lang=cpp
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        nums.insert(nums.begin(), 0);
        for(int i = 1; i < nums.size(); ++i){
            while(i != nums[i] && nums[i] < nums.size() && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }

        for(int i = 1; i < nums.size(); ++i){
            if(i != nums[i]) res.push_back(i);
        }
        return res;        
    }
};
// @lc code=end

