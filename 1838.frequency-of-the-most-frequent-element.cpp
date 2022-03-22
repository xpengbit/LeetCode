/*
 * @lc app=leetcode id=1838 lang=cpp
 *
 * [1838] Frequency of the Most Frequent Element
 */

// @lc code=start
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int j = 0, ret = 1;
        long cnt = 0;
        for(int i = 1; i < nums.size(); ++i){
            cnt += (long)(i - j)*(long)(nums[i] - nums[i - 1]);
            while(cnt > k){
                cnt -= (nums[i] - nums[j]);
                j++;
            }
            ret = max(ret, i - j + 1);
        }
        return ret;
    }
};
// @lc code=end
//把数组排序后，遍历每一个i。然后向前找j，使得cnt += (nums[i] - nums[j]) < k
//这样是一个n^2的复杂度。可以想到用一个滑动窗口。i每向右移动一次 cnt += (i - j) * (nums[i] - nums[i - 1]);
//这时候如果cnt > k, j需要向右移动。 cnt -= (nums[i] - nums[j]);


