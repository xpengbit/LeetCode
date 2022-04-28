/*
 * @lc app=leetcode id=1546 lang=cpp
 *
 * [1546] Maximum Number of Non-Overlapping Subarrays With Sum Equals Target
 */

// @lc code=start
class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        int i = 0, sum = 0, res = 0;
        m[0] = 1;
        while(i < nums.size()){
            sum += nums[i];
            if(m.count(sum - target)){
                res++;
                sum = 0;
                m.clear();
            }
            m[sum]++;
            i++;
        }
        return res;
    }
};
// @lc code=end
//map + prefix sum

