/*
 * @lc app=leetcode id=1840 lang=cpp
 *
 * [1840] Maximum Building Height
 */

// @lc code=start
class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        sort(restrictions.begin(), restrictions.end());
        int m = restrictions.size();
        vector<int> h(m);
        vector<int> pos(m);
        vector<int> limit(m);

        for(int i = 0; i < m; ++i){
            pos[i] = restrictions[i][0];
            limit[i] = restrictions[i][1];
        }

        h[0] = 0;
        for(int i = 1; i < m; ++i)
            h[i] = min(limit[i], h[i - 1] + pos[i] - pos[i - 1]);

        for(int i = m - 2; i >= 1; --i)
            h[i] = min(h[i], h[i + 1] + pos[i + 1] - pos[i]);

        // h[i - 1] + x = h[i] + y
        // pos[i - 1] + x = pos[i] - y
        // peak = h[i - 1] + (h[i] - h[i - 1] + pos[i] - pos[i - 1]) / 2;
        int res = 0;
        for(int i = 1; i < m; ++i){
            int peak = h[i - 1] + (h[i] - h[i - 1] + pos[i] - pos[i - 1]) / 2;
            res = max(res, peak);
        }
        
        //从最后一个约束点到终点的最大高度
        res = max(res, h[m - 1] + n - pos[m - 1]);

        return res; 
    }
};
// @lc code=end

