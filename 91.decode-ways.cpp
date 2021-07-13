/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        
        const int n = s.length();
        int w1 = 1;
        int w2 = 1;
        for(int i = 1; i < n; i++){
            int w = 0;
            if(!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
            if(isValid(s[i])) w += w1;
            if(isValid(s[i -1], s[i])) w += w2;
            w2 = w1;
            w1 = w;
        }
        return w1;
        /*Memorization + recursion*/
        /*if(s.length() == 0) return 0;
        m_ways[""] = 1;
        return helper(s);*/
        
        /*return helper2(s, 0, s.length() - 1);*/
    }
private:
    bool isValid(char c) { return c != '0'; }
    bool isValid(char c1, char c2){
        const int sum = (c1 - '0')*10 + (c2 - '0');
        return sum >= 10 && sum <= 26;
    }
    unordered_map<string, int> m_ways;
    unordered_map<int, int> m_ways2;
    int helper(const string s){
        if(m_ways.count(s)) return m_ways[s];
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;

        int w = helper(s.substr(1));
        const int prefix = stoi(s.substr(0,2));
        if(prefix >= 10 && prefix <=26)
            w += helper(s.substr(2));
        m_ways[s] = w;
        return w;
    }

    int helper2(const string s, int l, int r){
        if(m_ways2.count(l)) return m_ways2[l];
        if(s[l] == '0') return 0;
        if(l >= r) return 1;
        int w = helper2(s, l + 1, r);

        int prefix = (s[l] - '0')*10 + (s[l + 1] - '0');
        if(prefix >= 10 && prefix <= 26) 
            w += helper2(s, l + 2, r);
        
        m_ways2[l] = w;
        return w;
    }

};
// @lc code=end

