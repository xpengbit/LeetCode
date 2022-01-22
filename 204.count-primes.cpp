/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        int count = 0;
        vector<bool> num(n, true);
        for(int i = 2; i < n; ++i){
            if(num[i] == false) continue;
            count++;
            for(int j = 2; j * i < n; ++j)
                num[i * j] = false;
        }
        
        return count;
    }
};
// @lc code=end

