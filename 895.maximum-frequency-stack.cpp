/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
    unordered_map<int, int> mp; /*value to frequenc*/
    priority_queue<vector<int>> pq;
    int pos;
public:
    FreqStack() {
       pos = 0; 
    }
    
    void push(int val) {
        mp[val]++;
        pos++;
        pq.push({mp[val], pos, val});
    }
    
    int pop() {
        auto tmp = pq.top(); pq.pop();
        mp[tmp[2]]--;
        return tmp[2];    
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

