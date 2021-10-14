/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*计数排序解法*/
        vector<int> color(3);
        for(int num : nums) ++color[num];
        int cur = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < color[i]; ++j){
                nums[cur++] = i;
            }
        }

        /*双指针解法*/
        int l = 0, r = nums.size() - 1, cur = 0;
        while(cur <= r){
            if(nums[cur] == 0) swap(nums[cur++], nums[l++]);
            else if(nums[cur] == 2) swap(nums[cur], nums[r--]);
            else cur++;
        }    
    }
};
// @lc code=end

