/*
 * @lc app=leetcode id=556 lang=cpp
 *
 * [556] Next Greater Element III
 */

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        //这道题本质上是一个next permutation
        vector<int> digit;
        while(n > 0){
            digit.push_back(n % 10);
            n /= 10; 
        }
        int i = 1;
        while(i < digit.size() && digit[i] >= digit[i - 1])
            i++;
        if(i == digit.size()) return -1;
        
        int j = 0;
        while(digit[j] <= digit[i])
            j++;
        swap(digit[i], digit[j]);
        sort(digit.begin(), digit.begin() + i);
        reverse(digit.begin(), digit.begin() + i);

        long ret = 0;
        for(int i = digit.size() - 1; i >= 0; i--){
            ret = ret * 10 + digit[i];
        }

        if(ret > INT_MAX) return -1;
        return ret;
                
    }
};
// @lc code=end

