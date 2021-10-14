/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*解法1：纵向扫描*/
        /*if(strs.empty()) return "";
        for(int indx = 0; indx < strs[0].size(); ++indx){
            for(int j = 1; j < strs.size(); ++j){
                if(strs[0][indx] != strs[j][indx]) return strs[0].substr(0, indx);
            }
        }
        return strs[0];*/

        /*解法2：这种方法给输入字符串数组排了个序，想想这样做有什么好处？既然是按字母顺序排序的话，
        那么有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端，
        那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以只需要找首尾字母串的共同前缀即可。
        比如例子1排序后为 ["flight", "flow", "flower"]，例子2排序后为 ["cat", "dog", "racecar"]，
        虽然例子2没有共同前缀，但也可以认为共同前缀是空串，且出现在首尾两端的字符串中。由于是按字母顺序排的，
        而不是按长度，所以首尾字母的长度关系不知道，为了防止溢出错误，只遍历而这种较短的那个的长度，找出共同前缀返回即可，
        参见代码如下：*/
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while(i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};
// @lc code=end

