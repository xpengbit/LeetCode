/*
 * @lc app=leetcode id=1462 lang=cpp
 *
 * [1462] Course Schedule IV
 */

// @lc code=start
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses);
        vector<unordered_set<int>> preCourse(numCourses);

        for(auto edge : prerequisites){
            graph[edge[0]].push_back(edge[1]);
            inDegree[edge[1]] += 1;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            preCourse[i].insert(i);
            if(inDegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(int next : graph[cur]){
                for(int pre : preCourse[cur])
                    preCourse[next].insert(pre);
                inDegree[next] -= 1;
                if(inDegree[next] == 0) q.push(next);
            }
        }

        vector<bool> res;
        for(auto query : queries)
            res.push_back(preCourse[query[1]].find(query[0]) != preCourse[query[1]].end());
        
        return res;
    }
};
// @lc code=end

