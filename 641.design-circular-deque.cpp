/*
 * @lc app=leetcode id=641 lang=cpp
 *
 * [641] Design Circular Deque
 */

// @lc code=start
class MyCircularDeque {
public:
    vector<int> cDeque;
    int front = 0, rear = -1, size = 0, capacity;
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cDeque = vector<int>(k);
        capacity = k;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(isFull()) return false;
        if(--front < 0)  front += capacity;
        cDeque[front] = value;
        size++;
        if(size == 1)  rear = front;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(isFull()) return false;
        rear = ++rear % capacity;
        cDeque[rear] = value;
        size++;
        return true;        
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(isEmpty()) return false;
        front = ++front % capacity;
        size--;
        return true;    
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(isEmpty()) return false;
        if(--rear < 0)  rear += capacity;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        return isEmpty()? -1 : cDeque[front];    
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        return isEmpty() ? -1 : cDeque[rear];        
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;    
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size == capacity;    
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
// @lc code=end

