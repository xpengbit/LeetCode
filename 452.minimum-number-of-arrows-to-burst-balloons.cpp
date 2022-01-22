/*
 * @lc app=leetcode id=452 lang=cpp
 *
 * [452] Minimum Number of Arrows to Burst Balloons
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        /*int n = points.size();
        sort(points.begin(), points.end(), cmp);
        int overlap = 0, choose = 0;
        for(int i = 1; i < n; ++i){
            if(points[i][0] <= points[choose][1]) ++overlap;
            else choose = i;
        }
        return n - overlap;*/
        sort(points.begin(), points.end(), cmp);
        int b = points[0][1];
        int ret = 1;
        for(auto point : points){
            if(point[0] <= b) continue;
            else{
                b = point[1];
                ret++;
            }
        }
        return ret;
    }
};
// @lc code=end

