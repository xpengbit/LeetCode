/*[LeetCode] 286. Walls and Gates 墙和门
 You are given a m x n 2D grid initialized with these three possible values.
-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4*/
  

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        //BFS solution
        /*queue<pair<int, int>> q;
        int m = rooms.size(), n = rooms[0].size();
        vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(rooms[i][j] == 0)
                    q.push({i, j});
            }
        }

        while(!q.empty()){
            auto [x, y] = q.front(); q.pop();
            for(int i = 0; i < 4; ++i){
                int nx = x + dirs[i].first, ny = y + dirs[i].second;
                if(nx < 0 ||  ny < 0 || nx >= m || ny >= n || rooms[nx][ny] < room[x][y] + 1) continue;
                rooms[nx][ny] = rooms[x][y] + 1;
                q.push({nx, ny});
            }
        }*/
        
        //DFS solution
        int m = rooms.size(), n = rooms[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(room[i][j] == 0)
                    dfs(rooms, i, j, 0);
            }
        }
    }

    void dfs(vector<vector<int>>& rooms, int i, int j, int val){
        if(i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size() || rooms[i][j] < val) return;
        rooms[i][j] = val;
        dfs(rooms, i + 1, j, val + 1);
        dfs(rooms, i - 1, j, val + 1);
        dfs(rooms, i, j + 1, val + 1);
        dfs(rooms, i, j - 1, val + 1);
    }
};