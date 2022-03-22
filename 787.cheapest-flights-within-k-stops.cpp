/*
 * @lc app=leetcode id=787 lang=cpp
 *
 * [787] Cheapest Flights Within K Stops
 */

// @lc code=start
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        //DP
        /*vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX/2));
        dp[0][src] = 0;
        for(int k = 1; k <= K + 1; ++k){
            for(auto flight : flights){
                int a = flight[0];
                int b = flight[1];
                int w = flight[2];
                dp[k][b] = min(dp[k][b], dp[k - 1][a] + w);
                dp[k][b] = min(dp[k][b], dp[k - 1][b]);
            }
        }
        int ret = dp[K + 1][dst];
        return ret == INT_MAX/2 ? -1 : ret;*/
        
        //Dijkstra
        unordered_map<int, vector<pair<int, int>>> graph(n);
        for(auto flight : flights){
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<vector<int>> visited(n, vector<int>(K + 2, INT_MAX/2));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> q;
        q.push({0, 0, src});
        visited[src][0] = 0;

        while(!q.empty()){
            int cost = q.top()[0];
            int step = q.top()[1];
            int cur = q.top()[2];
            q.pop();
            if(cur == dst) return cost;
            if(step == K + 1) continue;
            for(auto [d, c] : graph[cur]){
                if(cost + c < visited[d][step + 1]){
                    visited[d][step + 1] = cost + c;
                    q.push({cost + c, step + 1, d});
                }
            }
        }
        return -1;
    }
};
// @lc code=end

