/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0 or n == 1) return {0};
        vector<int> res;
        vector<int> degree(n);
        unordered_map<int, vector<int>> tree;
        queue<int> q;
        for(auto e : edges){
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        for(int i = 0; i < n; i++){
            if(degree[i] == 1)
                q.push(i);
        }
        while(!q.empty()){
            int n = q.size();
            vector<int> vi;
            for(int i = 0; i < n; i++){
                int tmp = q.front();
                q.pop();
                vi.push_back(tmp);
                for(int e : tree[tmp]){
                    if(--degree[e] == 1)
                        q.push(e);
                }
            }
            res = vi;
        }
        return res;    
    }
};
// @lc code=end

