/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*快慢指针*/
        int cur = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[cur] != nums[i])
                nums[++cur] = nums[i];
        }
        while(cur < n){
            if(nums[cur] == nums[index]) ++cur;
            else nums[++index] = nums[cur++];
        }
        return nums.empty() ? 0 : index + 1;    
    }
};
// @lc code=end

