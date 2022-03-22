/*
 * @lc app=leetcode id=1744 lang=cpp
 *
 * [1744] Can You Eat Your Favorite Candy on Your Favorite Day?
 */

// @lc code=start
typedef long long ll;
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        candiesCount.insert(candiesCount.begin(), 0);
        vector<ll> sum(n + 1);
        vector<bool> ret;
        for(int i = 1; i <=n; ++i){
            sum[i] = sum[i - 1] + candiesCount[i];
        }

        for(auto q : queries){
            ll t = q[0] + 1;
            ll d = q[1] + 1;
            ll cap = q[2];

            if(1*(d - 1) >= sum[t])
                ret.push_back(false);
            else if(cap * d <= sum[t - 1])
                ret.push_back(false);
            else
                ret.push_back(true);
        }
        return ret;
    }
};
// @lc code=end
//这个题主要考察前缀和。
//考虑两种情况。1.糖很少，即使每天吃一个也吃完了。 1*(d - 1) >= sum[t]
//2.糖太多， 即使每天吃cap个，还是吃不完 cap * d <= sum[t - 1]

