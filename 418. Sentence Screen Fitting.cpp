/*
 * @lc app=leetcode id=418 lang=cpp
 *
 * [418] Sentence Screen Fitting
 */

// @lc code=start
class Solution {
public:
    int wordTyping(vector<string>& sentence, int rows, int cols) {
        string str;
        for(string s : sentence){
            if(s.size() > cols) return 0;
            str += s + " ";
        }
        int indx = 0;
        int len = str.size();
        for(int i = 0; i < row; ++i){
            indx += cols;
            while(str[indx % len] != " ")
                --indx;
            indx += 1;
        }

        return indx / len;
    }
};
// @lc code=end

