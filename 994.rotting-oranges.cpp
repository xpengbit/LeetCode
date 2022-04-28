/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int res = 0, fresh = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        while(!q.empty() && fresh > 0){
            int len = q.size();
            while(len--){
                auto [x, y] = q.front(); q.pop();
                for(int i = 0; i < 4; ++i){
                    int nx = x + dir[i].first;
                    int ny = y + dir[i].second;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
            res++;
        }
        return fresh > 0 ? -1 : res;    
    }
};
// @lc code=end

