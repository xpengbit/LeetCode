/*
 * @lc app=leetcode id=1801 lang=cpp
 *
 * [1801] Number of Orders in the Backlog
 */

// @lc code=start
using PII = pair<int, int>;
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<PII> buy;
        priority_queue<PII, vector<PII>, greater<>> sell;
        long M = 1e9 + 7;
        long res = 0;

        for(auto order : orders){
            res = (res + order[1]) % M;
            if(order[2] == 0){
                while(!sell.empty() && order[1] > 0 && order[0] >= sell.top().first){
                    auto [price, amount] = sell.top();
                    sell.pop();
                    long num = min(long(amount), long(order[1]));
                    amount -= num;
                    order[1] -= num;
                    res = (res - num * 2 + M) % M;
                    if(amount > 0)
                        sell.push({price, amount});
                }
                if(order[1] > 0)
                    buy.push({order[0], order[1]});
            }
            else{
                while(!buy.empty() && order[1] > 0 && order[0] <= buy.top().first){
                    auto [price, amount] = buy.top();
                    buy.pop();
                    long num2 = min(long(amount), long(order[1]));
                    amount -= num2;
                    order[1] -= num2;
                    res = (res - num2 * 2 + M) % M;
                    if(amount > 0)
                        buy.push({price, amount});
                }
                if(order[1] > 0)
                    sell.push({order[0], order[1]});
            }
        }
        return res;    
    }
};
// @lc code=end

