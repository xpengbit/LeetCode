//Design a max stack that supports push, pop, top, peekMax and popMax.

//push(x) -- Push element x onto stack.
//pop() -- Remove the element on top of the stack and return it.
//top() -- Get the element on the top.
//peekMax() -- Retrieve the maximum element in the stack.
//popMax() -- Retrieve the maximum element in the stack, and remove it. 
//If you find more than one maximum elements, only remove the top-most one.

class MaxStack{
public:
    stack<int> stk;
    stack<int> maxStk;
    MaxStack(){
    }

    void push(int x){
        stk.push(x);
        if(maxStk.empty() or x > maxStk.top())
            maxStk.push(x);
    }

    void pop(){
        if(stk.top() == maxStk.top())
            maxStk.pop();
        stk.pop();
    }

    int top(){
        return stk.top();
    }

    int peekMax(){
        return maxStk.top();
    }

    int popMax(){
        int tmp = maxStk.top();
        maxStk.pop();
        return tmp;
    }
};