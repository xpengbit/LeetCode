/*
 * @lc app=leetcode id=847 lang=cpp
 *
 * [847] Shortest Path Visiting All Nodes
 */

// @lc code=start
class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int ret = 0, n = graph.size(), target = 0;
        queue<pair<int, int>> q;
        unordered_set<string> visited;
        for(int i = 0; i < n; ++i){
            int mask = (1 << i);
            target |= mask;
            visited.insert(to_string(mask) + "-" + to_string(i));
            q.push({mask, i});
        }

        while(!q.empty()){
            for(int k = q.size(); k > 0; --k){
                auto tmp = q.front(); q.pop();
                if(tmp.first == target) return ret;
                for(int nxt : graph[tmp.second]){
                    int m = tmp.first | (1 << nxt);
                    string str = to_string(m) + "-" + to_string(nxt);
                    if(visited.count(str)) continue;
                    visited.insert(str);
                    q.push({m, nxt});
                }
            }
            ret++;
        }
        return -1;    
    }
};
// @lc code=end

