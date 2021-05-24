/*
 * @lc app=leetcode id=1381 lang=cpp
 *
 * [1381] Design a Stack With Increment Operation
 */

// @lc code=start
class CustomStack {
    stack<int> s;
    int n; 
    vector<int> inc;
public:
    CustomStack(int maxSize) {
       n = maxSize;
       inc = vector<int>(n , 0); 
    }
    
    void push(int x) {
        if(s.size() < n) s.push(x);   
    }
    
    int pop() {
        int i = s.size() - 1;
        if(i < 0) return -1;
        if(i > 0) inc[i - 1] += inc[i];
        int tmp = s.top();
        tmp = tmp + inc[i];
        inc[i] = 0;
        s.pop();
        return tmp;
    }
    
    void increment(int k, int val) {
        int i = min(k, (int)s.size()) - 1;
        if(i >= 0) inc[i] += val;            
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
// @lc code=end

