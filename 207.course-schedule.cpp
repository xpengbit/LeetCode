/*
 * @lc app=leetcode id=207 lang=cpp
 *
 * [207] Course Schedule
 */

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(numCourses);
        for(int i = 0; i < prerequisites.size(); i++){
            int end = prerequisites[i][0];
            int start = prerequisites[i][1];
            graph[start].push_back(end);
            indegree[end]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int tmp = q.front();
            q.pop();
            count++;
            for(int adj : graph[tmp]){
                if(--indegree[adj] == 0)
                    q.push(adj);
            }
        }
        return count == numCourses;   
    }
};
// @lc code=end

