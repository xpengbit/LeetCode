/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 */

// @lc code=start
class Solution {
public:
    string shortestPalindrome(string s) {
        //Manache
        string t = "#";
        for(char c : s){
            t.push_back(c);
            t.push_back('#');
        }

        int n = t.size();
        vector<int> p(n, 0);
        int l = 0;
        int maxCenter = -1, maxRight = -1;
        for(int i = 0; i < n; ++i){
            int r = 0;
            if(i < maxRight){
                int j = maxCenter * 2 - i;
                r = min(p[j], maxRight - i);
            }

            while(i - r >= 0 && i + r < n && t[i - r] == t[i + r])
                r++;
            p[i] = r - 1;

            if(i + p[i] > maxRight){
                maxRight = i + p[i];
                maxCenter = i;
            }

            if(i - p[i] == 0)
                l = max(l, (p[i] * 2 + 1) / 2);
        }
        string tmp = s.substr(l);
        reverse(tmp.begin(), tmp.end());
        return tmp+s;
    }
};
// @lc code=end

// p[i] 表示以i为圆心的回文串半径
//X [X X X X X X X  X  X X X X X X X] X X
//   * & %   % & *     * & %   % & * 
//         j       mc        i     mR
//  j = mc * 2 - i
//  r = min(p[j], mR -i);
