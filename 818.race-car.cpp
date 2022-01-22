/*
 * @lc app=leetcode id=818 lang=cpp
 *
 * [818] Race Car
 */

// @lc code=start
class Solution {
public:
    int racecar(int target) {
        //bottom-up DP
        auto dp = new int[target + 1];
        //vector<int> dp(target + 1);
        for(int i = 1; i <= target; ++i){
            dp[i] = INT_MAX;

            int m = 1, j = 1;
            for(; j < i; j = (1 << ++m) - 1){
                for(int p = 0, q = 0; p < j; p = (1 << ++q) - 1){
                    dp[i] = min(dp[i], m + 1 + q + 1 + dp[i - (j - p)]);
                }
            }

            dp[i] = min(dp[i], m + ( i == j ? 0 : 1 + dp[j - i]));
        }
        return dp[target];
    }
};

/*class Solution {
public:
    // Top-down dp
    int racecar(int target) {
        auto dp = new int[target + 1];
        Array.fill(dp, 1, dp.length(), -1);
        return racecar(target, dp);
    }
private:
    int racecar(int i, int[] dp){
        if(dp[i] > 0) return dp[i];
        int m = 1, j = 1;
        dp[i] = INT_MAX;
        for(; j < i; j = (1 << ++m) - 1)
            for(int p = 0, q = 0; p < j; p = (1 << ++q) - 1)
                dp[i] = min(dp[i], m + 1 + q + 1 + rececar(i - (j - p), dp));

        dp[i] = min(dp[i], m + (j == i ? 0 : 1 + rececar(j - i, dp)));

        return dp[i];
    }
};


class Solution {
public:
    int racecar(int target) {
        int ret = 0;
        queue<pair<int, int>> q;
        q.push({0, 1});
        unordered_set<string> visited;
        visited.insert(to_string(0) + "-" + to_string(1));
        while(!q.empty()){
            for(int i = q.size(); i > 0; --i){
                int pos = q.front().first, speed = q.front().second;
                q.pop();
                if(pos == target) return ret;
                int newpos = pos + speed, newspeed = speed * 2;
                string str = to_string(newpos) + "-" + to_string("newspeed");
                if(!visited.count(str) && newpos > 0 && newpos < target * 2){
                    q.push({newpos, newspeed});
                    visited.insert(str);
                }

                newpos = pos, newspeed = (speed > 0 ? -1 : 1);
                str = to_string(pos) + "-" + to_string(newspeed);
                if(!visited.count(str) && newpos > 0 && newpos < target * 2){
                    q.push({newpos, newspeed});
                    visited.insert(str);
                }
            }
            ret++;
        }
        return -1;
    }
};
*/
// @lc code=end

