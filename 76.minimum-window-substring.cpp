/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        //双指针
        unordered_map<char, int> table;
        for(char c : t) ++table[c];
        int N = table.size();
        
        string res = "";
        unordered_map<char, int> mp;
        int i = 0, len = INT_MAX, count = 0;
        for(int j = 0; j < s.size(); ++j){
            mp[s[j]]++;
            if(mp[s[j]] == table[s[j]]) count++;
            while(count == N){
                if(len > j - i + 1){
                    len = j - i + 1;
                    res = s.substr(i, len);
                }
                --mp[s[i]];
                if(mp[s[i]] == table[s[i]] - 1)
                    count--;
                i++;
            }
        }
        return res;
    }
};
// @lc code=end

