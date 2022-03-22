/*
 * @lc app=leetcode id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

// @lc code=start
class Solution {
    vector<int> next[100000];
    int indegree[100000];
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int res = 1;
        
        for(auto edge : edges){
            next[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        
        unordered_set<char> Set(colors.begin(), colors.end());
        for(char c : colors){
            if(Set.find(c) == Set.end()) continue;
            int t = helper(c - 'a', colors);
            if(t == -1) return -1;
            res = max(res, t);
        }
        return res;
    }

    int helper(int k, string colors){
        int n = colors.size();
        int node = 0; //node count to check if there is loop
        vector<int> in(n, 0); //copy of indegree
        vector<int> count(n, 0); //count of every color;
        for(int i = 0; i < n; ++i)
            in[i] = indegree[i];
        
        queue<int> q;
        for(int i = 0; i < n; ++i){
            if(in[i] == 0){
                q.push(i);
                node++;
                if(colors[i] - 'a' == k) count[i]++;
            }
        }

        int ret = 1; //max value of vevery color
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto n : next[cur]){
                count[n] = max(count[n], count[cur] + (colors[n] - 'a' == k));
                ret = max(count[n], ret);
                in[n]--;
                if(in[n] == 0){
                    node++;
                    q.push(n);
                }
            }
        }
        if(node != n) return -1;
        return ret;
    }
};
// @lc code=end

