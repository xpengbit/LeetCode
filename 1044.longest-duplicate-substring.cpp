/*
 * @lc app=leetcode id=1044 lang=cpp
 *
 * [1044] Longest Duplicate Substring
 */

// @lc code=start
using ULL = uint64_t;
class Solution {
    unordered_map<int, int> len2str;
public:
    string longestDupSubstring(string s) {
        int left = 1, right = s.size() - 1;
        while(left < right){
            int mid = right - (right - left) / 2;
            if(isOk(s, mid))
                left = mid;
            else
                right = mid - 1;
        }
        if(isOk(s, left))
            return s.substr(len2str[left], left);
        else
            return "";    
    }

    bool isOk(string& s, int len){
        unordered_set<ULL> Set;
        ULL base = 31;
        ULL hash = 0;
        ULL pow_base_len = 1;
        for(int i = 0; i < len; ++i)
            pow_base_len = pow_base_len * base;
        
        for(int i = 0; i < s.size(); ++i){
            hash = hash * base + (s[i] - 'a');
            if(i >= len)
                hash = hash - pow_base_len * (s[i - len] - 'a');
            if(i >= len - 1){
                if(Set.find(hash) != Set.end()){
                    len2str[len] = i - len + 1;
                    return true;
                }
                Set.insert(hash);
            }
        }
        return false;
    }
};
// @lc code=end

//二分搜值 + rolling hash
//二分搜值搜的是duplicated substring 的长度。即rolling hash 滑窗的长度。
