/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int x0, y0, zero = 1, res = 0;  //zero 初始化为1，是把目标点也计算进去。

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    x0 = i;
                    y0 = j;
                }
                else if(grid[i][j] == 0)
                    zero++;
            }
        }

        dfs(grid, x0, y0, zero, res);
        return res;
    }

    void dfs(vector<vector<int>>& grid, int x, int y, int& cnt, int& res){
        int m = grid.size(), n = grid[0].size();
        if(x < 0 || x >=m || y < 0 || y >= n || grid[x][y] < 0) return;
        if(grid[x][y] == 2){
            if(cnt == 0)
                res++;
            return;
        }

        grid[x][y] = -2;
        --cnt;
        dfs(grid, x + 1, y, cnt, res);
        dfs(grid, x - 1, y, cnt, res);
        dfs(grid, x, y + 1, cnt, res);
        dfs(grid, x, y - 1, cnt, res);
        ++cnt;
        grid[x][y] = 0;

    }
};
// @lc code=end

