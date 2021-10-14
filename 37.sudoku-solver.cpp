/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);   
    }
private:
    bool isValid(vector<vector<char>>& board, int i, int j, int val){
        for(int k = 0; k < 9; ++k){
            if(board[i][k] != '.' && board[i][k] == val) return false;
            if(board[k][j] != '.' && board[k][j] == val) return false;
            int row = i/ 3 * 3 + k / 3, col = j / 3 * 3 + k % 3;
            if(board[row][col] != '.' && board[row][col] == val) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int x, int y){
        if(x == 9) return true;
        if(y >= 9) return helper(board, x + 1, 0);
        if(board[x][y] != '.') return helper(board, x, y + 1);
        for(char c = '1'; c <= '9'; ++c){
            if(!isValid(board, x, y, c)) continue;
            board[x][y] = c;
            if(helper(board, x, y + 1)) return true;
            board[x][y] = '.';
        }
        return false;
    }
};
// @lc code=end

