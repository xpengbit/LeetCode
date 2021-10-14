/*
 * @lc app=leetcode id=4 lang=cpp
 *
 * [4] Median of Two Sorted Arrays
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total & 0x1)
            return findKth(nums1, 0, nums2, 0, total/2 + 1);
        else
            return (findKth(nums1, 0, nums2, 0, total/2) + findKth(nums1, 0, nums2, 0, total/2 + 1))/2.0;        
    }
private:
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);

        int midVal1 = (i + k/2 - 1 < nums1.size()) ? nums1[i + k/2 - 1] : INT_MAX;
        int midVal2 = (j + k/2 - 1 < nums2.size()) ? nums2[j + k/2 - 1] : INT_MAX;
        if(midVal1 < midVal2)
            return findKth(nums1, i + k/2, nums2, j, k - k/2);
        else
            return findKth(nums1, i, nums2, j + k/2, k - k/2);
    }
};
// @lc code=end

