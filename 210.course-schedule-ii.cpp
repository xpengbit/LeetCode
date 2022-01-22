/*
 * @lc app=leetcode id=210 lang=cpp
 *
 * [210] Course Schedule II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses); 
        for(auto pre : prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int course = 0;
        while(!q.empty()){
            int tmp = q.front(); q.pop();
            course++;
            res.push_back(tmp);
            for(int adj : graph[tmp]){
                if(--indegree[adj] == 0)
                    q.push(adj);
            }
        }
        if(course == numCourses) return res;
        else return {};
    }
};
// @lc code=end

