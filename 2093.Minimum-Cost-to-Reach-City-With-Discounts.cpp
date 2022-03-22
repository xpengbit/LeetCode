/*本题看上去就像最短路径问题。难点在于，我们在某个位置时，无法知道当前使用折扣的权利是否为最优方案。
因此本题的“图”的节点定义应该设计为二元参数 {node, discountsLeft}。在用Dijsktra遍历图的过程中，
即使多次来到相同的位置，但是剩余折扣次数的不同的话，应当视为不同的“状态”。
所以我们记录答案的数据应该是为二位的：dist[node][discounts]。
在PQ里弹出当前的{curNode, discountsLeft}后，可以扩展加入PQ的“状态”包括两部分，“使用折扣权利”或者“不使用”：*/


using PII = pair<int, int>;
using AI3 = array<int, 3>;

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) 
    {
        vector<vector<PII>> next;
        for(auto x : highways){
            next[x[0]].push_back({x[1], x[2]});
            next[x[1]].push_back({x[0], x[2]});
        }

        priority_queue<AI3, vector<AI3>, greater<>> pq;
        pq.push({0, 0, discounts});
        vector<vector<int>> cost(n, vector<int>(discounts + 1, INT_MAX));

        while(!pq.empty()){
            auto [c, node, times] = pq.top();
            pq.pop();
            if(cost[node][times] < INT_MAX) continue;
            cost[node][times] = c;
            if(node == n - 1) return c;

            for(auto [nxt, toll] : next[node]){
                if(cost[nxt][times] < INT_MAX) continue;
                pq.push({c + toll, nxt, times});
                if(times >= 1)
                    pq.push({c + toll/2, nxt, times - 1});
            }
        }
        return -1;    
    }
};