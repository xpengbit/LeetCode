/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dic(wordList.begin(), wordList.end());
        if(!dic.count(endWord)) return res;
        
        queue<vector<string>> q;
        vector<string> start;
        start.push_back(beginWord);
        q.push(start);
        while(!q.empty()){
            if(!res.empty()) return res;
            int n = q.size();
            for(int j = 0; j < n; j++){
                vector<string> tmp = q.front();
                q.pop();
                string s = tmp.back();
                dic.erase(s);
                if( s == endWord){
                    res.push_back(tmp);
                }
                else{
                    for(int i = 0; i < s.size(); i++){
                        char old = s[i];
                        for(char c = 'a'; c <='z'; c++){
                            s[i] = c;
                            if(dic.count(s)){
                                tmp.push_back(s);
                                q.push(tmp);
                                tmp.pop_back();
                            }
                        }
                        s[i] = old;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end

