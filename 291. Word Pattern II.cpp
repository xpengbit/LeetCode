/*
 * @lc app=leetcode id=291 lang=cpp
 *
 * [291] Word Pattern II
 */

// @lc code=start
class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> mp;
        return dfs(pattern, 0, string s, 0, mp);
    }

    bool dfs(string pattern, int p, string s, int r, unordered_map<char, string>& mp){
        if(p == pattern.size() && r == s.size()) return true;
        if(p == pattern.size() || r == s.size()) return false;

        char c = pattern[p];
        for(int i = r; i < string.size(); ++i){
            string str = s.substr(r, i - r + 1);
            if(mp.count[c] && mp[c] == str){
                if(dfs(pattern, p + 1, s, r + 1, mp)) return true;;
            }
            else if(!mp.count[c]){
                bool flag = 0;
                for(auto m : mp){
                    if(m.second == str) flag = 1;
                }

                if(!flag){
                    mp[c] = str;
                    if(dfs(pattern, p + 1, s, r + 1, mp)) return true;
                    mp.erase(c);
                }
            }
        }
        return false;
    }
};
// @lc code=end