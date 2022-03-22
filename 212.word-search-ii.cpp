/*
 * @lc app=leetcode id=212 lang=cpp
 *
 * [212] Word Search II
 */

// @lc code=start
class Solution {
    class TrieNode{
    public:
        TrieNode* next[26];
        string isWord;
        TrieNode(){
            isWord = "";
            for(int i = 0; i < 26; ++i){
                next[i] = NULL;
            }
        }
    };

    TrieNode* root;
    int m, n;
    vector<string> res;
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        root = new TrieNode(); 
        for(string w : words){
            TrieNode* cur = root;
            for(char c : w){
                if(cur->next[c - 'a'] == NULL)
                    cur->next[c - 'a'] = new TrieNode();
                cur = cur->next[c -'a'];
            }
            cur->isWord = w;
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                 if(root->next[board[i][j] - 'a'] != NULL)
                     dfs(board, i, j, root);
            }
        }
        return res;    
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* cur){
        char c = board[i][j];
        if(cur->next[c - 'a'] == NULL) return;

        cur = cur->next[c - 'a'];
        if(cur->isWord != ""){
            res.push_back(cur->isWord);
            cur->isWord = "";
        }
        
        board[i][j] = '*';
        for(int k = 0; k < 4; ++k){
            int x = i + dir[k].first;
            int y = j + dir[k].second;
            if(x < 0 || x >= m || y < 0 || y >= n || board[x][y] == '*') continue;
            dfs(board, x, y, cur);
        }
        board[i][j] = c;
    }
};
// @lc code=end
//这道题使用Trie + Backtracking.设计Trie的时候使用了一个小trick。在word的结尾记录word.
//然后再DFS的时候找到一个word，加入res后把Trie的word字符串设置成“”。这样去重。
//backtrack的时候要记得还原。这里没有使用一个tempStr来记录当前字符串。
//也没有使用visited来记录已经访问过的字符串。而是把访问过的borad改成'*', 然后backtrack的时候再改回来。
