/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> direct = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        if(!heights.size()) return res;
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> pOcean = BFS(heights, 0, m, n);
        vector<vector<int>> aOcean = BFS(heights, 1, m, n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pOcean[i][j] == 1 and aOcean[i][j] == 1)
                    res.push_back({i, j});
            }
        }
        return res; 
    }
    /*BFS solution. 先用p ocean标记metrix,再用A ocean 标记。在metrix里同时为true的点返回*/
    vector<vector<int>> BFS(vector<vector<int>>& heights, int type, int m, int n){
        vector<vector<int>> mark(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<int>> q;
        if(type == 0){
            for(int j = 0; j < n; j++){
                visited[0][j] = true;
                q.push({0,j});
            }
            for(int i = 1; i < m; i++){
                visited[i][0] = true;
                q.push({i, 0});
            }
        }
        else{
            for(int j = 0; j < n; j++){
                visited[m-1][j] = true;
                q.push({m-1,j});
            }
            for(int i = 0; i < m-1; i++){
                visited[i][n-1] = true;
                q.push({i, n-1});
            }
        }
        while(!q.empty()){
            int s = q.size();
            vector<int> tmp = q.front();
            q.pop();
            mark[tmp[0]][tmp[1]] = 1;
            for(auto d : direct){
                int x = tmp[0] + d[0];
                int y = tmp[1] + d[1];
                if(x >= 0 and y >= 0 and x < m and y < n and !visited[x][y] and heights[x][y] >= heights[tmp[0]][tmp[1]]){
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return mark;
    }
};
// @lc code=end

