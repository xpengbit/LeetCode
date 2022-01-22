/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long A = numerator;
        long B = denominator;
        if(A == 0) return "0";
        int sign = 1;
        if(A < 0){
            sign *= -1;
            A = labs(A);
        }
        if(B < 0){
            sign *= -1;
            B = labs(B);
        }
        string res;
        if(sign == -1) res = "-";
        
        res += to_string(A/B);
        long C = A % B;
        if(C == 0) return res;
        else res += ".";

        unordered_map<int, int> mp;
        while(C != 0 && mp.find(C) == mp.end()){
            mp[C] = res.size();
            res.push_back('0' + C*10/B);
            C = C*10%B;
        }
        if(C == 0) return res;
        res.insert(res.begin() + mp[C], '(');
        res.push_back(')');

        return res;
    }
};
// @lc code=end

