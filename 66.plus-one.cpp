/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return {};
        int n = digits.size();
        int c = 1;
        for(int i = n - 1; i >= 0; --i){
            int num = digits[i] + c;
            c = num / 10;
            digits[i] = num % 10;
            if(c == 0) break;
        }
        if(c > 0) digits.insert(digits.begin(), 1);
        return digits;   
    }
};
// @lc code=end

