/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
/*class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> next;
        vector<int> indegree(numCourses);

        for(auto pre : prerequisites){
            next[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i)
            if(indegree[i] == 0)
                q.push(i);
        
        int count = 0; 
        while(!q.empty()){
            int cur = q.front(); q.pop();
            count++;
            for(int x : next[cur]){
                indegree[x]--;
                if(indegree[x] == 0)
                    q.push(x);
            }
        }
        return count = numCourses;
    }
};*/

class Solution {
    unordered_map<int, vector<int>> graph;
    vector<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        visited.resize(numCourses, 0);
        for(auto pre : prerequisites)
            graph[pre[1]].push_back(pre[0]);

        for(int i = 0; i < numCourses; ++i)
            if(dfs(i) == false) return false;

        return true;            
    }

    bool dfs(int node){
        if(visited[node] == 1) return true;
        if(visited[node] == 2) return false;

        visited[node] = 2;
        for(auto x : graph[node]){
            if(dfs(x) == false) return false;
        }
        visited[node] = 1;
        return true;
    }
};
// @lc code=end

