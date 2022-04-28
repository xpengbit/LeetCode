/*
 * @lc app=leetcode id=1192 lang=cpp
 *
 * [1192] Critical Connections in a Network
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        int cnt = 1;
        vector<int> time(n), low(n);
        vector<vector<int>> res;
        unordered_map<int, vector<int>> g;

        for(auto c : connections){
            g[c[0]].push_back(c[1]);
            g[c[1]].push_back(c[0]);
        }

        helper(g, 0, -1, cnt, time, low, res);
        
        return res;    
    }

    void helper(unordered_map<int, vector<int>>& g, int cur, int pre, int& cnt, vector<int>& time, vector<int>& low, vector<vector<int>>& res){
        time[cur] = low[cur] = cnt++;
        for(auto nxt : g[cur]){
            if(time[nxt] == 0){
                helper(g, nxt, cur, cnt, time, low, res);
                low[cur] = min(low[cur], low[nxt]);
            }
            else if(pre != nxt){
                low[cur] = min(low[cur], time[nxt]);
            }

            if(low[nxt] > time[cur])
                res.push_back({cur, nxt});
        }
    }
};
// @lc code=end

//求一个bridge 或者叫做 ciritcal edge

