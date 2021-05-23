/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */

    stack<vector<int>> stk;
    MinStack() {
    }
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
            return;
        }
        stk.push({val, min(val, stk.top()[1])});
    }
    
    void pop() {
        stk.pop();        
    }
    
    int top() {
        return stk.top()[0];
    }
    
    int getMin() {
        return stk.top()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

