/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 */

// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = pattern.size(), i = 0;
        unordered_map<char, string> mp;
        istringstream in(s);
        for(string word; in >> word; ++i){
            if(i >= n) return false;
            if(mp.count(pattern[i])){
                if(mp[pattern[i]] != word) return false;
            }
            else{
                for(auto a : mp){
                    if(a.second == word) return false;
                }
            }
            mp[pattern[i]] = word;
        }
        return i == n;
    }
};
// @lc code=end

