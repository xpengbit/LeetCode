/*
 * @lc app=leetcode id=1717 lang=cpp
 *
 * [1717] Maximum Score From Removing Substrings
 */

// @lc code=start
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if(x < y){
            reverse(s.begin(), s.end());
            swap(x, y);
        }
        
        int ret = 0;
        string s1;
        for(char c : s){
            s1.push_back(c);
            while(s1.size() >= 2 && s1.substr(s1.size() - 2) == "ab"){
                s1.pop_back();
                s1.pop_back();
                ret += x;
            }
        }
        string s2;
        for(char c : s1){
            s2.push_back(c);
            while(s2.size() >= 2 && s2.substr(s2.size() - 2) == "ba"){
                s2.pop_back();
                s2.pop_back();
                ret += y;
            }
        }

        return ret;
    }
};
// @lc code=end

