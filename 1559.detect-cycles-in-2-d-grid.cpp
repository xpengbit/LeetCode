/*
 * @lc app=leetcode id=1559 lang=cpp
 *
 * [1559] Detect Cycles in 2D Grid
 */

// @lc code=start
class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        //BFS
        int m = grid.size(), n = grid[0].size();
        auto visited = vector<vector<int>>(m, vector<int>(n, 0));
        vector<pair<int, int>> direct{{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<vector<int>> q; //i, j, and 到达i,j 的方向
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(visited[i][j]) continue;
                visited[i][j] = 1;
                q.push({i, j, -1}); //第一个点没有方向
                while(!q.empty()){
                    int x = q.front()[0];
                    int y = q.front()[1];
                    int d = q.front()[2];
                    q.pop();
                    for(int k = 0; k < 4; ++k){
                        int nx = x + direct[k].first;
                        int ny = y + direct[k].second;
                        if(d == 0 && k == 1) continue;
                        if(d == 1 && k == 0) continue;
                        if(d == 2 && k == 3) continue;
                        if(d == 3 && k == 2) continue;
                        if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                        if(grid[x][y] != grid[nx][ny]) continue;
                        if(visited[nx][ny]) return true;

                        visited[nx][ny] = 1;
                        q.push({nx, ny, k});
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

//这个题是一个BFS, 但是有点不同的是在queue里面会用一个vector带多一点的信息。
//除了x,y 的坐标， 还有到达x,y 的方向。

