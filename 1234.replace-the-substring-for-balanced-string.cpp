/*
 * @lc app=leetcode id=1234 lang=cpp
 *
 * [1234] Replace the Substring for Balanced String
 */

// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        /*Sliding Window*/
        int n = s.size(), k = n / 4, left = 0, res = n;
        unordered_map<char, int> mp;
        for(char c : s) ++mp[c];
        for(int i = 0; i < n; ++i){
            --mp[s[i]];
            while(left < n && mp['Q'] <= k && mp['W'] <= k && mp['E'] <= k && mp['R'] <= k){
                res = min(res, i - left + 1);
                ++mp[s[left++]];
            }
        }
        return res;    
    }
};
// @lc code=end

