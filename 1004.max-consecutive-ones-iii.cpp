/*
 * @lc app=leetcode id=1004 lang=cpp
 *
 * [1004] Max Consecutive Ones III
 */

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*int n = nums.size();
        int res = 0, count = 0, i = 0;
        for(int j = 0; j < n; ++j){
            if(nums[j] == 1){
                res = max(res, j - i + 1);
                continue;
            }
            count++; //这里count先加了一次。相当于count从1开始。
            while(count > k){
                if(nums[i] == 0) count--;
                i++;
            }
            res = max(res, j - i + 1);
        }
        return res;*/
        int n = nums.size();
        int res = 0, count = 0, j = 0;
        for(int i = 0; i < n; ++i){
            while(j < n && (nums[j] == 1 || (nums[j] == 0 && count < k))){//count从0开始计数这里是< k
                if(nums[j] == 0) count++;
                j++;
            }//这里跳出的时候count 已经大于k， j已经在一个0的位置
            res = max(res, j - i);
            if(nums[i] == 0) count--;
        }
        return res;
    }
};
// @lc code=end
//这类求连续子数组的问题。首先要想到双指针。固定一个边界，寻找另外一个边界。

