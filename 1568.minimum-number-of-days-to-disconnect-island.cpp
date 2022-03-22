/*
 * @lc app=leetcode id=1568 lang=cpp
 *
 * [1568] Minimum Number of Days to Disconnect Island
 */

// @lc code=start
class Solution {
    int m, n;
public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int countof1 = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1) countof1++;
            }
        }
        if(countof1 == 1) return 1;
        if(countof1 == 0) return 0;

        if(isLand(grid) > 1) return 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 0 ) continue;
                grid[i][j] = 0;
                if(isLand(grid) > 1) return 1;
                grid[i][j] = 1;
            }
        }
        return 2;    
    }

    int isLand(vector<vector<int>>& grid){
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<pair<int, int>> dir({{-1, 0}, {1, 0}, {0, 1}, {0, -1}});
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(visited[i][j] || grid[i][j] == 0) continue;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k = 0; k < 4; ++k){
                        int a = x + dir[k].first;
                        int b = y + dir[k].second;
                        if(a < 0 || a >= m || b < 0 || b >= n) continue;
                        if(visited[a][b] || grid[a][b] == 0) continue;
                        q.push({a, b});
                        visited[a][b] = 1;
                    }
                }
                count++;
                if(count > 1) return 2;
            }
        }
        return count;
    }
};
// @lc code=end

//注意到陆地变成多个岛屿，一定可以通过改变角落上的1得到。这样最大的days为2；
//如果本来就有多个岛屿 days return 0；
//遍历每一个land 改变成 0 ,如果改变它能得到多个岛屿。return 1；
//剩余的情况 return 2;
//有corner case : [[0,0,0],[0,1,0],[0,0,0]] and [[0, 0],[0, 0]] 需要统计grid里1的个数，如果是1，返回1. 是0， 返回0；
//这个题考察DFS or BFS 统计岛屿的数量
