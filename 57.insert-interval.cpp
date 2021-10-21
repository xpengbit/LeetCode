/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t n = intervals.size(), cur = 0;
        for(size_t i = 0; i < n; ++i){
            if(intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
                cur++;
            }
            else if(newInterval[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;    
    }
};
// @lc code=end

