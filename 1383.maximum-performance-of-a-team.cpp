/*
 * @lc app=leetcode id=1383 lang=cpp
 *
 * [1383] Maximum Performance of a Team
 */

// @lc code=start
class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int M = 1e9+7;
        vector<pair<int, int>> engin;
        for(int i = 0; i < n; ++i)
           engin.push_back({efficiency[i], speed[i]});
        
        sort(engin.begin(), engin.end(), [](pair<int, int>&a, pair<int, int>& b){
            return a.first > b.first;
        });
        priority_queue<int, vector<int>, greater<>> pq;
        long long res = 0, sum = 0;

        for(auto [e, s] : engin){
            sum += s;
            pq.push(s);
            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            res = max(res, sum * e);
        }
        return res % M;
    }
};
// @lc code=end

