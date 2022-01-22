/*
 * @lc app=leetcode id=864 lang=cpp
 *
 * [864] Shortest Path to Get All Keys
 */

// @lc code=start
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size(), ret = 0, keyCnt = 0;
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '@'){
                    q.push({i * n + j, 0});
                    visited.insert(to_string(i * n + j) + '-' + to_string(0));
                }
                if(grid[i][j] >= 'a' && grid[i][j] <= 'f') ++keyCnt;
            }
        }
        while(!q.empty()){
            for(int k = q.size(); k > 0; --k){
                auto [cur, cnt] = q.front(); q.pop();
                if(cnt == (1 << keyCnt) - 1) return ret;
                for(int i = 0; i < 4; ++i){
                    int x = cur / n + dir[i].first, y = cur % n + dir[i].second, key = cnt;
                    if(x < 0 || y < 0 || x >= m || y >= n) continue;
                    char c = grid[x][y];
                    if(c == '#') continue;
                    if(c >= 'A' && c <= 'F' && ((key >> (c - 'A')) & 1) == 0) continue;
                    if(c >= 'a' && c <= 'f')  key |= 1 << (c - 'a');
                    string str = to_string(x * n + y) + "-" + to_string(key);
                    if(visited.count(str)) continue;
                    visited.insert(str);
                    q.push({x * n + y, key});
                }
            }
            ret++;
        }
        return -1;    
    }
};
// @lc code=end

