/*
 * @lc app=leetcode id=218 lang=cpp
 *
 * [218] The Skyline Problem
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res, height;
        multiset<int> s;  //会排序
        for(auto & b : buildings){
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }
        sort(height.begin(), height.end());

        int cur, pre = 0;
        s.insert(0);
        for(auto & h : height){
            if(h[1] < 0) s.insert(-h[1]);
            else s.erase(s.find(h[1]));
            cur = *s.rbegin();
            if(cur != pre){
                res.push_back({h[0], cur});
                pre = cur;
            }
        }
        return res;           
    }
};
// @lc code=end

