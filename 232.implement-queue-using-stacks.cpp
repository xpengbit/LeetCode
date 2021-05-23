/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
class MyQueue {
public:
    stack<int> s;
    stack<int> q;
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);    
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = peek();
        q.pop();
        return tmp;    
    }
    
    /** Get the front element. */
    int peek() {
        if(q.empty()){
            while(!s.empty()){
                q.push(s.top());
                s.pop();
            }
        }
        return q.top(); 
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty() and q.empty();    
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

