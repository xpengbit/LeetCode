/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
       int m = firstList.size(), n = secondList.size();
       if(m == 0 || n == 0) return {};
       int i = 0, j = 0;
       vector<vector<int>> res;
       while(i < m && j < n){
           if(firstList[i][1] < secondList[j][0]) ++i;
           else if(secondList[j][1] < firstList[i][0]) ++j;
           else{
               int a = max(firstList[i][0], secondList[j][0]);
               int b = min(firstList[i][1], secondList[j][1]);
               res.push_back({a, b});
               if(firstList[i][1] < secondList[j][1]) ++i;
               else ++j;
           }
       }
       return res; 
    }
};
// @lc code=end

