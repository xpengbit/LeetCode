/*
 * @lc app=leetcode id=621 lang=cpp
 *
 * [621] Task Scheduler
 */

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        unordered_map<char, int> Map;
        priority_queue<int> pq;
        for(auto c : tasks)
            Map[c]++;

        for(auto it : Map)
            pq.push(it.second);
        
        int res = 0;
        while(!pq.empty()){
            int k = min((int)pq.size(), n);
            vector<int> tmp;
            for(int i = 0; i < k; ++i){
                int t = pq.top(); pq.pop();
                t--;
                if(t != 0) tmp.push_back(t); //这里不能立马加回pq，因为需要取n个任务。
            }
            if(tmp.size() != 0) //这种情况不是最后一行，需要补足IDLE，res + n;
                res += n;
            else   //最后一行，+k
                res += k;

            for(auto x : tmp)   //把 -1 过后的frequency 加回pq
                pq.push(x);
        }
        return res;
    }
};
// @lc code=end

//这个题可以使用模拟最优解的过程。从frequency最大的开始取n + 1个任务(因为是between n)。

