/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> Map;
        for(char c : s)
            Map[c]++;

        vector<int> visited(256, 0);
        string str;
        for(char c : s){
            if(visited[c]){
                Map[c]--;
                continue;
            }
            else{
                while(!str.empty() && str.back() > c && Map[str.back()] > 0){
                    visited[str.back()] = 0;
                    str.pop_back();
                }
                str.push_back(c);
                visited[c] = 1;
                Map[c]--;
            }
        }
        return str; 
    }
};
// @lc code=end

