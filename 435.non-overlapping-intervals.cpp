/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non-overlapping Intervals
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>&a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        //这种Intervals问题一般使用greedy算法。先sort
        //排序有两种，对starting point，对ending pint排
        //starting point解决: the minimum number of intervals to cover the whole range
        //ending point 解决：the maxmum number of intervals that non-overlapping

        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int ret = 0, choose = 0;
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] < intervals[choose][1]) ++ret;
            else choose = i;
        }
        return ret;    
    }
};
// @lc code=end

