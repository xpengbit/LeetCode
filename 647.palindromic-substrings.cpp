/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        //dp N^2
        /*if(s.empty()) return 0;
        int n = s.size();
        int res = 0;
        /*dp[i][j] 为i，j之间的回文数量
        vector<vector<int>> dp(n, vector<int>(n));

        for(int i = n - 1; i >= 0; i--){
            for(int j = i ; j < n; j++){
                dp[i][j] = s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1]);
                if(dp[i][j]) res++;
            }
        }
        return res;*/

        //Manache
        string t = "#";
        for(char c : s){
            t.push_back(c);
            t.push_back('#');
        }
        int maxCenter = -1, maxRight = -1, n = t.size();
        vector<int> p(n);
        int ret = 0;
        for(int i = 0; i < n; ++i){
            int r = 0;
            if(i < maxRight){
                int j = maxCenter*2 - i;
                r = min(p[j], maxRight - i);
            }
            while(i -r >= 0 && i + r < n && t[i - r] == t[i + r])
                r++;
            p[i] = r - 1;
            ret += (p[i] + 1)/ 2;
            if(i + p[i] > maxRight){
                maxRight = i + p[i];
                maxCenter = i;
            } 
        }
        return ret;
    }
};
// @lc code=end

// @lc code=end

// p[i] 表示以i为圆心的回文串半径
//X [X X X X X X X  X  X X X X X X X] X X
//   * & %   % & *     * & %   % & * 
//         j       mc        i     mR
//  j = mc * 2 - i
//  r = min(p[j], mR -i);

