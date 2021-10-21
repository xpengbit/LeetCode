/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long lower = nums1[0] + nums2[0], upper = nums1.back() + nums2.back();
        while(lower < upper){
            long mid = lower + (upper - lower) / 2;
            long cnt = countLowerandEqual(mid, nums1, nums2);
            if(cnt < k)
                lower = mid + 1;
            else
                upper = mid;
        }
        long m = lower;
        vector<vector<int>> res1;
        vector<vector<int>> res2;
        for(int i = 0; i < nums1.size(); ++i){
            int j = 0;
            while(j < nums2.size() && nums1[i] + nums2[j] <= m){
                if(nums1[i] + nums2[j] < m)
                    res1.push_back({nums1[i], nums2[j]});
                else
                    res2.push_back({nums1[i], nums2[j]});
                
                ++j;
            }
        }
        int t = min(res2.size(), k - res1.size());
        for(int i = 0; i < t; ++i){
            res1.push_back(res2[i]);
        }

        return res1;
    }
private:
    long countLowerandEqual(long m, vector<int>& nums1, vector<int>& nums2){
        long res = 0;
        int j = nums2.size() - 1;
        for(int i = 0; i < nums1.size(); ++i){
            while(j >= 0 && nums1[i] + nums2[j] > m)
                --j;
            res += j + 1;
        }
        return res;
    }
};
// @lc code=end

