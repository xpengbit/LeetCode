/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int len1 = m - 1, len2 = n - 1, len = m + n - 1;
        while(len1 >= 0 && len2 >= 0){
            nums1[len--] = nums1[len1] >= nums2[len2] ? nums1[len1--] : nums2[len2--];
        }
        while(len2 >= 0){
            nums1[len--] = nums2[len2--];
        }
    }
};
// @lc code=end

