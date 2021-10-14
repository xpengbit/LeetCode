/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        /*if(s.empty()) return {};
        vector<int> res, cnt(26, 0);
        int m = s.size(), n = p.size();
        for(char c : p) ++cnt[c - 'a'];
        for(int i = 0; i < m; ++i){
            bool cmp = true;
            vector<int> tmp = cnt;
            for(int j = i; j < i + n; ++j){
                if(--tmp[s[j] - 'a'] < 0) {
                    cmp = false;
                    break;
                }
            }
            if(cmp == true) res.push_back(i);
        }
        return res;*/

        /*解法2：sliding window*/
        if(s.empty()) return {};
        vector<int> res, m(256, 0);
        int left = 0, right = 0, cnt = p.size(), n = s.size();
        for(char c : p) ++m[c];
        while(right < n){
            if(m[s[right++]]-- >= 1) --cnt;
            if(cnt == 0) res.push_back(left);
            if(right - left == p.size() && m[s[left++]]++ >= 0) ++cnt;
        }
        return res;         
    }
};
// @lc code=end

