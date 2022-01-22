/*
 * @lc app=leetcode id=1263 lang=cpp
 *
 * [1263] Minimum Moves to Move a Box to Their Target Location
 */

// @lc code=start
class Solution {
public:
    int minPushBox(vector<vector<char>>& grid) {
        int res = 0, target, box, start;
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        unordered_set<string> Set;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 'B') box = i * n + j;
                else if(grid[i][j] == 'S') start = i * n + j;
                else if(grid[i][j] == 'T') target =  i * n + j; 
            }
        }

        q.push({box, start});
        while(!q.empty()){
            for(int i = q.size(); i > 0; --i){
                auto t = q.front(); q.pop();
                int box = t.first, player = t.second;
                if(box == target) return res;
                int x = box / n, y = box % n;
                for(auto d : dir){
                    int nx = x + d.first, ny = y + d.second, xp = x - d.first, yp = y - d.second;
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == '#') continue;
                    if(xp < 0 || xp >= m || yp < 0 || yp >= n || grid[xp][yp] == '#') continue;
                    string str = to_string(box) + "_" + to_string(xp * n + yp);
                    if(Set.count(str)) continue;
                    if(canReach(grid, player, xp * n + yp, box)){
                        q.push({nx * n + ny, box});
                        Set.insert(str);
                    } 
                }
            }
            res++;
        }
        return -1;
    }

    bool canReach(vector<vector<char>>& grid, int start, int target, int box){
        int m = grid.size(), n = grid[0].size();
        vector<int> visited(m * n);
        queue<int> q{{start}};
        visited[start] = 1;
        grid[box/n][box%n] = '#';
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(t == target){
                grid[box/n][box%n] = '.';
                return true;
            } 
            for(auto d : dir){
                int x = t / n + d.first, y = t % n + d.second;
                if(x < 0 || x >= m || y < 0 || y >= n || visited[x* n + y] || grid[x][y] == '#') continue;
                visited[x * n + y] = 1;
                q.push(x * n + y);
            }
        }
        grid[box/n][box%n] = '.';
        return false;
    }
};
// @lc code=end

