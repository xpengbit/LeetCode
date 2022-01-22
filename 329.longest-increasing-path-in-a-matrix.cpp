/*
 * @lc app=leetcode id=329 lang=cpp
 *
 * [329] Longest Increasing Path in a Matrix
 */

// @lc code=start
/*class Solution {
    int m, n;
    vector<vector<int>>  memo;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        int res = 1;
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                res = max(res, dfs(matrix, i, j));  
            }
        }
        return res;    
    }

    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(memo[i][j] != 0) return memo[i][j];
        int ret = 1;
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        for(int k = 0; k < 4; ++k){
            int x = i + dir[k].first;
            int y = j + dir[k].second;
            if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[i][j]) continue;
            int len = 1 + dfs(matrix, x, y);
            ret = max(ret, len);
        }
        memo[i][j] = ret;
        return ret;
    }
};*/

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> memo(m, vector<int>(n, 0));
        int ret = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(memo[i][j] > 0) continue;
                queue<pair<int, int>> q{{{i, j}}};
                int cnt = 1;
                while(!q.empty()){
                    cnt++;
                    int len = q.size();
                    for(int k = 0; k < len; ++k){
                        auto cur = q.front(); q.pop();
                        for(auto d : dir){
                            int x = cur.first + d.first;
                            int y = cur.second + d.second;
                            if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= matrix[cur.first][cur.second] || cnt < memo[x][y]) continue;
                            memo[x][y] = cnt;
                            ret = max(ret, cnt);
                            q.push({x, y});
                        } 
                    }
                }
            }
        }
        return ret;
    }
};
// @lc code=end

