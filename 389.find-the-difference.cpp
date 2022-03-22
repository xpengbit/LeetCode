/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.empty()) return t[0];
        unordered_map<char, int> Map;
        for(char c : s)
            Map[c]++;
        
        char ret;
        for(char c : t){
            if(!Map.count(c)) return c;
            else{
                Map[c]--;
                if(Map[c] < 0){
                    ret = c;
                    break;
                }
            }
        }
        return ret;
    }
};
// @lc code=end

