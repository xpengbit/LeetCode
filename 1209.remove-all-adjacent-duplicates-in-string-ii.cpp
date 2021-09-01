/*
 * @lc app=leetcode id=1209 lang=cpp
 *
 * [1209] Remove All Adjacent Duplicates in String II
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size(), i = 0;
        vector<int> cnt(n);
        for(int j = 0; j < n; ++j, ++i){
            s[i] = s[j];
            cnt[i] = (i > 0 && s[i - 1] == s[i]) ? cnt[i - 1] + 1 : 1;
            if(cnt[i] == k) i -= k;
        } 
        return s.substr(0, i);

        /*解法2：使用栈。用一个数组来模拟栈*/
        /*string res;
        vector<pair<int, char>> st{{0, '#'}};
        for(char c : s){
            if(st.back().second != c)
                st.push_back({1, c});
            else if(++st.back().first == k)
                st.pop_back(); 
        }
        for(auto &a : st)
            res.append(a.first, a.second);
        return res;*/
    }
};
// @lc code=end

