/*
 * @lc app=leetcode id=1774 lang=cpp
 *
 * [1774] Closest Dessert Cost
 */

// @lc code=start
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int res = 0, diff = INT_MAX, cost = 0;
        int n = toppingCosts.size();

        for(int base : baseCosts){
            for(int state = 0; state < pow(3, n); ++state){
                int topping = 0;
                int cur = state;
                for(int i = 0; i < n; ++i){
                    int tmp = cur % 3;
                    topping += toppingCosts[i] * tmp;
                    cur /= 3;
                }
                cost = base + topping;
                if(abs(cost - target) < diff){
                    diff = abs(cost - target);
                    res = cost;
                }
                else if(abs(cost - target) == diff && cost < res)
                    res = cost;
            }
        }
        return res;    
    }
};
// @lc code=end

//设计一个3进制数，然后遍历每一种可能

