/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 */

// @lc code=start

/*BFS + PQ*/
/*typedef pair<int, int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<PII>> graph(n + 1);
        for(auto t : times)
            graph[t[0]].push_back({t[1], t[2]});
        
        priority_queue<PII, vector<PII>, greater<>> pq; //小顶堆
        pq.push({0, k});
        int ret = 0;
        vector<int> visited(n + 1, 0);

        while(!pq.empty()){
            auto [d, cur] = pq.top(); pq.pop();
            if(visited[cur] == 1) continue;
            visited[cur] = 1;
            ret = max(ret, d);
            
            for(auto [next, weight] : graph[cur]){
                pq.push({weight + d, next});
            }
        }

        for(int i = 1; i <= n; ++i)
            if(visited[i] == 0) return -1;
        
        return ret;
    }
};*/

/*N^2 solution*/
/*typedef pair<int, int> PII;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<PII>> graph(n + 1);
        for(auto t : times)
            graph[t[0]].push_back({t[1], t[2]});
        
        int ret = 0;
        vector<int> visited(n + 1, 0);
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for(int i = 1; i <= n; ++i){
            int minNode = -1;
            int minDis = INT_MAX;
            for(int j = 1; j <= n; ++j){
                if(visited[j] == 0 && dist[j] < minDis){
                    minNode = j;
                    minDis = dist[j];
                }
            }
            
            if(minNode == -1) break;
            visited[minNode] = 1;
            for(auto [next, d] : graph[minNode]){
                dist[next] = min(dist[next], dist[minNode] + d);
            }
        }

        for(int i = 1; i <= n; ++i)
            ret = max(ret, dist[i]);
        
        return ret == INT_MAX ? -1 : ret;
    }
};*/

/*FLOYED solution*/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //dp[i][j] the shortest distence between i to j
        auto dp = vector<vector<int>>(n + 1, vector<int>(n + 1, INT_MAX / 2));
           
        for(auto t : times)
            dp[t[0]][t[1]] = t[2];
        for(int i = 1; i <= n; ++i)
            dp[i][i] = 0;

        for(int k = 1; k <= n; ++k)
            for(int i = 1; i <= n; ++i)
                for(int j = 1; j <= n; ++j)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                
        int ret = 0;
        for(int i = 1; i <= n; ++i)
            ret = max(ret, dp[k][i]);

        return ret == INT_MAX ? -1 : ret;
    }
};
// @lc code=end

