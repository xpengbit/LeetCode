/*
 * @lc app=leetcode id=802 lang=cpp
 *
 * [802] Find Eventual Safe States
 */

// @lc code=start
/*DFS 判断是否有环标准套路*/
/*class Solution {
    vector<int> visited;
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        visited.resize(n, 0);
        for(int i = 0; i < n; ++i){
            if(dfs(i, graph) == true) res.push_back(i);
        }
        sort(res.begin(), res.end());
        return res;    
    }

    bool dfs(int node, vector<vector<int>>& graph){
        if(visited[node] == 1) return true;
        if(visited[node] == 2) return false;

        visited[node] = 2;
        for(int next : graph[node]){
            if(!dfs(next, graph)) return false;
        }
        visited[node] = 1;
        return true;
    }
};*/

/*BFS 从出度为0的节点往前，直到队列为空*/
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        vector<int> outDegree(n, 0);
        unordered_map<int, vector<int>> preNode;

        for(int i = 0; i < n; ++i){
            for(int j : graph[i]){
                preNode[j].push_back(i);
                outDegree[i]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(outDegree[i] == 0){
                q.push(i);
                res.push_back(i);
            }
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int pre : preNode[cur]){
                outDegree[pre]--;
                if(outDegree[pre] == 0){
                    q.push(pre);
                    res.push_back(pre);
                }
            }
        }
        sort(res.begin(), res.end());
        return res;    
    }
};

// @lc code=end

