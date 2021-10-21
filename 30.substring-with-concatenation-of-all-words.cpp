/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> mp;
        for(string word : words) ++mp[word];
        for(int i = 0; i <= (int)s.size() - n * len; ++i){
            int j = 0;
            unordered_map<string, int> cnt;
            for(j = 0; j < n; ++j){
                string t = s.substr(i + j * len, len);
                if(! mp.count(t)) break;
                if(++cnt[t] > mp[t]) break;
            }
            if(j == n) res.push_back(i);
        }
        return res;
    }
};
// @lc code=end

