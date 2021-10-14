/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<bool> visited(9);
        for(int i = 0; i < 9; ++i){
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j){
                if(! check(board[i][j], visited))
                    return false;
            }
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j){
                if(! check(board[j][i], visited))
                    return false;
            }
        }

        for(int r = 0; r < 3; ++r){
            for(int c = 0; c < 3; ++c){
                fill(visited.begin(), visited.end(), false);
                for(int i = r * 3; i < r * 3 + 3; ++i)
                    for(int j = c * 3; j < c * 3 + 3; ++j)
                        if(! check(board[i][j], visited)) return false;
            }
        }
        return true;
    }
private:
    bool check(char ch, vector<bool>& visited){
        if(ch == '.') return true;
        if(visited[ch - '1']) return false;
        return visited[ch - '1'] = true;
    }
};
// @lc code=end

