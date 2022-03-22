/*
 * @lc app=leetcode id=1514 lang=cpp
 *
 * [1514] Path with Maximum Probability
 */

// @lc code=start
using PDI = pair<double, int>;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i = 0; i < edges.size(); ++i){
            adj[edges[i][0]].push_back({edges[i][1], -log(succProb[i])});
            adj[edges[i][1]].push_back({edges[i][0], -log(succProb[i])});
        }

        priority_queue<PDI, vector<PDI>, greater<>> pq;
        pq.push({0, start});
        vector<double> prob(n, -1);

        while(!pq.empty()){
            auto [p, cur] = pq.top();
            pq.pop();
            if(prob[cur] != -1) continue;
            prob[cur] = p;
            if(cur == end) return exp(-prob[cur]);
            
            for(auto [nxt, np] : adj[cur]){
                if(prob[nxt] != -1) continue;
                pq.push({p + np, nxt});
            }
        }
        return 0;    
    }
};
// @lc code=end

//这个题需要吧prob转化为-log(prob)
//原本的题意是求最大乘积路径问题：
//maxmize prob(E1)*prob(E2)*...*prob(Ek) 
//= maxmize log[prob(E1)]+log[prob(E2)] + ... + log[prob(Ek)] 
//= minimize -log[prob(E1)] -log[prob(E2)] - ... -log[prob(Ek)]
//我们发现每条边的-log[prob(Ek)]都是正数，并且目标是最小化路径之和。所以考虑-log[prob(Ek)]为权重的图，原题就可以转化成标准的最短路径问题。

