/*
 * @lc app=leetcode id=1371 lang=cpp
 *
 * [1371] Find the Longest Substring Containing Vowels in Even Counts
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        int res = 0;
        vector<int> count(5, 0);
        unordered_map<int, int> Map;
        Map[0] = -1;

        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'a')
                count[0] = (count[0] + 1)%2;
            else if(s[i] == 'e')
                count[1] = (count[1] + 1)%2;
            else if(s[i] == 'i')
                count[2] = (count[2] + 1)%2;
            else if(s[i] == 'o')
                count[3] = (count[3] + 1)%2;
            else if(s[i] == 'u')
                count[4] = (count[4] + 1)%2;
            
            int code = 0;
            for(int i = 0; i < 5; ++i)
                code = (code << 1) + count[i];

            if(Map.count(code))
                res = max(res, i - Map[code]);
            else
                Map[code] = i;
        }
        return res;    
    }
};
// @lc code=end

