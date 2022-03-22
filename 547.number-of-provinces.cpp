/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        /*DFS solution*/
        /*int n = isConnected.size();
        int res = 0;
        vector<bool> isVisited(n, false);
        for(int i = 0; i < n; ++i){
            if(!isVisited[i]){
                dfs(isConnected, i, isVisited, n);
                res++;
            }
        }
        return res;*/

        /*Disjoint Set solution*/
        int n = isConnected.size();
        int res = n;
        DSU dsu(n);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i != j && isConnected[i][j]){
                    if(dsu.find(i) != dsu.find(j)){
                        dsu.unit(i, j);
                        res--;
                    }
                }
            }
        }
        return res;
    }
private:
    void dfs(vector<vector<int>>& isConnected, int i, vector<bool>& isVisited, int n){
        for(int j = 0; j < n; ++j){
            if(isConnected[i][j] == 1 && !isVisited[j]){
                isVisited[j] = true;
                dfs(isConnected, j, isVisited, n);
            }
        }
    }

    class DSU{
        vector<int> parent;
        public: DSU(int N){
            parent = vector<int>(N);
            for(int i = 0; i < N; ++i) parent[i] = i;
        }
        int find(int x){
            if(parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        void unit(int x, int y){
            parent[find(x)] = find(y);
        }
    };

    class DSU{
        vector<int> parent;
        public:
        DSU(int N){
            parent = vector<int>(N);
            for(int i = 0; i < n; ++i)
                parent[i] = i;
        }
        int find(int x){
            if(parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }

        void Union(int x, int y){
            parent[find(x)] = find(y);
        }
    }
};
// @lc code=end

