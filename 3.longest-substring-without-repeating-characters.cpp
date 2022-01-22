/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*if(s.length() == 0) return 0;
        int longest = 1;
        for(int i = 0; i < s.size() - 2; i++){
            set<char> st;
            st.insert(s[i]);
            for(int j = i + 1; j < s.size() -1; j++){
                if(!st.insert(s[j]).second){
                    longest = max(longest, (int)st.size());
                    break;
                }
            }
        }
        return longest;*/
        vector<int> mp(128, -1);
        int res = 0, i = -1, n = s.size();
        for(int j = 0; j < n; ++j){
            i = max(i, mp[s[j]]);
            mp[s[j]] = j;
            res = max(res, j - i);
        }
        return res;

        /*Test Case "abcabcbb"*/
        /*int res = 0, i = -1, n = s.size();
        unordered_map<int, int> mp;
        for(int j = 0; j < n; j++){
            if(mp.count(s[j]) && mp[s[j]] > i)  i = mp[s[j]];
            mp[s[j]] = j;
            res = max(res, j - i);
        }
        return res;*/
    }
};
// @lc code=end

