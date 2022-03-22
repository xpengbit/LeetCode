/*
 * @lc app=leetcode id=275 lang=cpp
 *
 * [275] H-Index II
 */

// @lc code=start
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        if(n == 0) return 0;
        int left = 0, right = n - 1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(n - mid <= citations[mid])
                right = mid;
            else
                left = mid + 1;
        }
        if(n - left <= citations[left])
            return n - left;
        else
            return 0;    
    }
};
// @lc code=end
//二分搜值

