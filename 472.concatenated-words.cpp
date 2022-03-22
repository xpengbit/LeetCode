/*
 * @lc app=leetcode id=472 lang=cpp
 *
 * [472] Concatenated Words
 */

// @lc code=start
class Solution {
    class TrieNode{
        public:
        TrieNode* next[26];
        bool isWord;
        TrieNode(){
            isWord = false;
            for(int i = 0; i < 26; ++i)
                next[i] = NULL;
        }
    };
    TrieNode* root;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        sort(words.begin(), words.end(), [&](string a, string b){return a.size() < b.size();});
        
        root = new TrieNode();
        vector<string> res;
        for(string w : words){
            if(!w.empty() && check(w))
                res.push_back(w);
            
            TrieNode* node = root;
            for(char c : w){
                if(node->next[c - 'a'] == NULL)
                    node->next[c - 'a'] = new TrieNode();
                node = node->next[c - 'a'];
            }
            node->isWord = true;
        }
        return res;
    }

    bool check(string s){
        int n = s.size();
        vector<int> visited(n, 0);
        return dfs(s, 0, visited);
    }

    bool dfs(string s, int index, vector<int>& visited){
        if(index == s.size()) return true;
        if(visited[index]) return false;
        TrieNode* node = root;
        for(int i = index; i < s.size(); ++i){
            if(node->next[s[i] - 'a'] != NULL){
                node = node->next[s[i] - 'a'];
                if(node->isWord && dfs(s, i + 1, visited))
                    return true;
            }
            else
                break;
        }
        visited[index] = true;
        return false;
    }
};
// @lc code=end
// Trie + dfs
//先把words排序，因为短的string一定不会由长的组成，然后按排序结果先搜索字典树，然后把这个string加入
//字典树，这样不用重复创建。
//dfs的时候用一个visited 数组，记录访问过的index
