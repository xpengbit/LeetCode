/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] ZigZag Conversion
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        int n = s.size(), i = 0;
        string res;
        vector<string> vec(numRows);
        while(i < n){
            for(int pos = 0; pos < numRows && i < n; ++pos)
                vec[pos] += s[i++];
            for(int pos = numRows - 2; pos >= 1 && i < n; --pos)
                vec[pos] += s[i++];
        }
        for(string v : vec) res += v;
        return res;    
    }
};
// @lc code=end

