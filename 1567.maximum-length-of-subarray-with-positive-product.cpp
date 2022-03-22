/*
 * @lc app=leetcode id=1567 lang=cpp
 *
 * [1567] Maximum Length of Subarray With Positive Product
 */

// @lc code=start
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] == 0) continue;
            int j = i, cnt = 0;
            int k = -1;
            while(j < nums.size() && nums[j] != 0){
                if(nums[j] < 0) cnt++;
                if(k == -1 && nums[j] < 0) k = j;
                if(cnt % 2 == 0)
                    res = max(res, j - i + 1);
                else
                    res = max(res, j - k);
                j++;
            }
            i = j;
        }
        return res;
    }
};
// @lc code=end
// 这类找subarray的题目，一般是要遍历subarray的右边界j。然后向前找符合条件的i.
//然后返回max[i:j];
//这个题需要找乘积为正数的subarray; 子数组里的negative 需要是偶数个，且不能有0；

