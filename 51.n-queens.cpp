/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, res);
        return res;    
    }
private:
    void dfs(int row, vector<string>& board, vector<vector<string>>& res){
        if(row == board.size()){
            res.push_back(board);
            return;
        }
        for(int j = 0; j < board.size(); ++j){
            if(!isValid(board, row, j)) continue;
            board[row][j] = 'Q';
            dfs(row + 1, board, res);
            board[row][j] = '.';
        }
    }

    bool isValid(vector<string> board, int row, int col){
        for(int i = 0; i < row; ++i){
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end

