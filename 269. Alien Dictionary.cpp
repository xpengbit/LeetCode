There is a new alien language which uses the latin alphabet. However, the order among letters are 
unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted 
lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Input:
[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<pair<char, char>> st;
        unordered_set<char> ch;
        vector<char> indegree(256);
        queue<char> q;
        string res;
        
        for(string w : words) ch.insert(w.begin(), w.end());
        for(int i = 0; i < words.size() - 1; ++i){
            int len = min(words[i].size(), words[i - 1].size()), j = 0;
            for(; j < len; ++j){
                if(word[i][j] != word[i + 1][j]){
                    st.insert({word[i][j], word[i + 1][j]});
                    break;
                }
            }
            if(j == len && words[i].size() > words[i + 1].size()) return "";
        }

        for(auto [a, b] : st) indegree[b]++;
        for(char c : ch){
            if(indegree[c] == 0)
                q.push(c);
                res += c;
        }

        while(!q.empty()){
            char c = q.front(); q.pop();
            for(auto [a, b] : st){
                if(a == c) indegree[b]--;
                if(indgree[b] == 0){
                    q.push(b);
                    res += b;
                }
            }
        }
        return res.size() == ch.size() ? res : "";
    }
};