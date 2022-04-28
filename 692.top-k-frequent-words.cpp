/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
    struct  cmp{
        bool operator()(pair<int, string>& a, pair<int, string>& b){
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> Map;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(auto w : words) Map[w]++;
        for(auto [w, f] : Map){
            pq.push({f, w});
            if(pq.size() > k) pq.pop();
        }

        vector<string> res(k);
        for(int i = k -1; i >= 0; --i){
            res[i] = pq.top().second;
            pq.pop();
        }

        return res;
    }
};
// @lc code=end

