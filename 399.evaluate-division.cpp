/*
 * @lc app=leetcode id=399 lang=cpp
 *
 * [399] Evaluate Division
 */

// @lc code=start
class Solution {
    unordered_map<string, vector<pair<string, double>>> graph;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        for(int i = 0; i < equations.size(); ++i){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }

        for(int i = 0; i < queries.size(); ++i){
            if(!graph.count(queries[i][0]) || !graph.count(queries[i][1]))
                res.push_back(-1.0);
            else if(queries[i][0] == queries[i][1])
                res.push_back(1.0);
            else{
                unordered_set<string> visited;
                double tmp = dfs(queries[i][0], queries[i][1], visited);
                res.push_back(tmp);
            }
        }
        return res;    
    }

    double dfs(string start, string end, unordered_set<string> visited){
        if(start == end) return 1.0;
        double tmp = -1.0;
        visited.insert(start);

        for(auto t : graph[start]){
            string s = t.first;
            if(visited.count(s)) continue;
            double tmp2 = dfs(s, end, visited);
            if(tmp2 != -1){
                tmp = t.second * tmp2;
                break;
            }
        }
        return tmp;
    }
};
// @lc code=end

