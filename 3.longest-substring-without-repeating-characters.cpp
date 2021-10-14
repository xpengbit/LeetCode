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
        /*Test Case "abcabcbb"*/
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.count(s[i]) && mp[s[i]] > left) left = mp[s[i]];
            mp[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
// @lc code=end

