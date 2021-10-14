/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board.size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(helper(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;   
    }
private:
    bool helper(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited){
        if(index == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y >= n || visited[x][y] || board[x][y] != word[index]) return false;
        visited[x][y] = true;
        bool res = helper(board, word, index + 1, x - 1, y, visited)
                || helper(board, word, index + 1, x + 1, y, visited)
                || helper(board, word, index + 1, x, y + 1, visited)
                || helper(board, word, index + 1, x, y - 1, visited);
        visited[x][y] = false;
        return res;
    }
};
// @lc code=end

