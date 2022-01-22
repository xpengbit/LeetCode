/*
 * @lc app=leetcode id=269 lang=cpp
 *
 * [269] Course Alien Dictionary
 */

// @lc code=start
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> next;
        unordered_map<char, int> inDegree;

        for(string word : words)
            for(char ch : word)
                inDegree[ch] = 0;
        
        for(int i = 0; i < words.size() - 1; ++i){
            string s = words[i];
            string t = words[i + 1];

            if(s.size() > t.size() && s.substr(0, t.size()) == t)
                return "";
            
            for(int j = 0; j < min(s.size(), t.size()); ++j){
                if(s[j] == t[j]) continue;
                if(next[s[j]].find(t[j]) == next[s[j]].end()){
                    next[s[j]].insert(t[j]);
                    inDegree[t[j]]++;
                }
                break;
            }
        }

        queue<int> q;
        for(auto x : inDegree){
            if(x.second == 0) q.push(x.first);
        }

        while(!q.empty()){
            char ch = q.front(); q.pop();
            res.push_back(ch);
            for(auto nxt : next[ch]){
                inDegree[nxt]--;
                if(inDegree[nxt] == 0){
                    q.push(nxt);
                }
            }
        }

        if(res.size() != inDegree.size())
            return "";
        else
            return res;
    }
};
// @lc code=end