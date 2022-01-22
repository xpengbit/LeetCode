/*
 * @lc app=leetcode id=1136 lang=cpp
 *
 * [1136] Diameter of Binary TreeCount Nodes With the Highest Score
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>)& relations) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(n + 1);
        for(auto relation : relations){
            graph[relation[0]].push_back(relation[1]);
            inDegree[relation[1]]++;
        }
        
        queue<int> q;
        for(int i = 1; i <= n; ++i){
            if(inDegree[i] == 0) q.push(i);            
        }

        int cnt = 0, semester = 0;
        while(!q.empty()){
            ++semester;
            int k = q.size();
            for(int i = 0; i < n; ++i){
                int cur = q.front(); q.pop();
                cnt++;
                for(int nxt : graph[cur]){
                    inDegree[nxt]--;
                    if(inDegree[nxt] == 0)
                        q.push(nxt);
                }
            }
        }
        if(cnt == n) return semester;
        else return -1;
    }
};