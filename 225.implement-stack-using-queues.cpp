/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> tmp = q1;
        q1 = q2;
        q2 = tmp;    
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int tmp = q1.front();
        q1.pop();
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();    
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        bool res;
        return res = q1.empty();        
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

