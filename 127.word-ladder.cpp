/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*Simple BFS */
        /*if(wordList.empty()) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
            int len = q.size();
            res++;
            for(int k = 0; k < len; k++){
                string tmp = q.front();
                q.pop();
                if(tmp == endWord) return res;
            
                for(int i = 0; i < tmp.size(); i++){
                    char original = tmp[i];
                    for(char c = 'a'; c <= 'z'; c++){
                        tmp[i] = c;
                        if(dict.count(tmp)){
                            q.push(tmp);
                            dict.erase(tmp);
                        }
                    }
                    tmp[i] = original; 
                }
            }
        }
        return 0;*/
        /*Bidirectional*/
        if(wordList.empty()) return 0;
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        int count = 0;
        while(!s1.empty() and !s2.empty()){
            count++;
            if(s1.size() > s2.size()){
                swap(s1, s2);
            }
            unordered_set<string> tmp;
            for(auto s: s1){
                for(int i = 0; i < s.size(); i++){
                    char old = s[i];
                    for(char c = 'a'; c <='z'; c++){
                        s[i] = c;
                        if(s2.count(s)) return count+1;
                        if(dict.count(s)){
                            dict.erase(s);
                            tmp.insert(s);
                        }
                    }
                    s[i] = old;
                }
            }
            s1 = tmp;
        }
        return 0;
    }
};
// @lc code=end

