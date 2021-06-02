/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0) return;
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][col-1] == 'O') dfs(i, col-1, board);
        }
        for(int j = 0; j < col; j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[row-1][j] == 'O') dfs(row-1, j, board);
        }
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'A') board[i][j] = 'O';
            }
        }
    }
private:
    void dfs(int i, int j, vector<vector<char>>& board){
        if(i < 0 or i > board.size() - 1 or j < 0  or j > board[0].size() -1) return;
        if(board[i][j] != 'O') return;
        board[i][j] = 'A';
        dfs(i - 1, j, board);
        dfs(i + 1, j, board);
        dfs(i, j - 1, board);
        dfs(i, j + 1, board);
    }
};
// @lc code=end

