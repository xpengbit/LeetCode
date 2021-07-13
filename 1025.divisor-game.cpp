/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int n) {
        memo = vector<bool>(n + 1);
        return helper(n);
    }
private:
    vector<bool> memo;
    bool helper(int n){
        if(n == 1) return false;
        if(memo[n] != NULL) return memo[n];
        bool canWin = false;
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0 && !helper(n - i)){
                canWin = true;
                break;
            }
        }
        return memo[n] = canWin;
    }
};
// @lc code=end

