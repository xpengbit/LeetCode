/*
 * @lc app=leetcode id=529 lang=cpp
 *
 * [529] Minesweeper
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if(board[click[0]][click[1]] == 'M')
            board[click[0]][click[1]] = 'X';
        else
            dfs(board, click[0], click[1]);
        return board;
    }
private:
    vector<vector<int>> direct = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};
    int checkNeighbors(vector<vector<char>>& board, int x, int y){
        int mines = 0;
        for(auto d : direct){
            int nx = x + d[0];
            int ny = y + d[1];
            if(nx >= 0 and ny >= 0 and nx < board.size() and ny < board[0].size() and board[nx][ny] == 'M')
                mines++;
        }
        return mines;
    }
    void dfs(vector<vector<char>>& board, int x, int y){
        if(x < 0 or y < 0 or x >= board.size() or y >= board[0].size())
            return;
        if(board[x][y] == 'E'){
            int mine = checkNeighbors(board, x, y);
            if(mine == 0){
                board[x][y] = 'B';
                for(auto d : direct){
                    int nx = x + d[0];
                    int ny = y + d[1];
                    dfs(board, nx, ny);
                }
            }
            else{
                board[x][y] = '0' + mine;
            }
        }
    }
};
// @lc code=end

