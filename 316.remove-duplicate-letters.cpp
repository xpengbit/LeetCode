/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(256);
        vector<int> cnt(256);
        string res = "0";
        for(char c : s) ++cnt[c];
        for(char c : s){
            --cnt[c];
            if(visited[c]) continue;
            while(c < res.back() && cnt[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += c;
            visited[c] = 1;
        }
        return res.substr(1);         
    }
};
// @lc code=end

