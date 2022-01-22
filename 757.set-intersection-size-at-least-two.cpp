/*
 * @lc app=leetcode id=757 lang=cpp
 *
 * [757] Set Intersection Size At Least Two
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] != b[1])
            return a[1] < b[1];
        else
            return a[0] > b[0];
    }
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), cmp);

        int a = intervals[0][1] - 1, b = intervals[0][1];
        int cnt = 2;
        for(int i = 1; i < n; ++i){
            if(intervals[i][0] <= a) continue;
            else if(intervals[i][0] <= b){
                cnt++;
                a = b;
                b = intervals[i][1];
            }
            else{
                cnt = cnt + 2;
                a = intervals[i][1] - 1;
                b = intervals[i][1];
            }
        }
        return cnt;    
    }
};
// @lc code=end

