/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    DFS(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
private:
    void DFS(int row, int col, vector<vector<char>>& grid){
        if(row < 0 or row > grid.size() - 1 or col < 0 or col > grid[0].size() - 1 or grid[row][col] != '1')
        return;
        grid[row][col] = '0';
        DFS(row+1, col, grid);
        DFS(row-1, col, grid);
        DFS(row, col+1, grid);
        DFS(row, col-1, grid);
    }
};
// @lc code=end

