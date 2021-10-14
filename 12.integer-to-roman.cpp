/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        /*string res = "";
        vector<int> val = {1000, 500, 100, 50, 10, 5, 1};
        vector<char> roma = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        for(int n = 0; n < 7; n += 2){
            int x = num / val[n];
            if(x < 4){
                for(int i = 1; i <= x; ++i) res += roma[n];
            }
            else if(x == 4) res = res + roma[n] + roma[n - 1];
            else if(x > 4 && x < 9){
                res = res + roma[n - 1];
                for(int i = 6; i <= x; ++i) res += roma[n];
            }
            else if(x == 9)
                res = res + roma[n] + roma[n - 2];
            
            num = num % val[n];
        }
        return res;*/

        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < val.size(); ++i){
            while(num >= val[i]){
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};
// @lc code=end

