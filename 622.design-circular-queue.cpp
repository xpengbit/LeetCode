/*
 * @lc app=leetcode id=622 lang=cpp
 *
 * [622] Design Circular Queue
 */

// @lc code=start
class MyCircularQueue {
private:
    vector<int> cq;
    int h, t, size = 0;
public:
    MyCircularQueue(int k) {
        cq = vector<int>(k);
        h = 0;
        t = -1;
        cout << cq.size(); 
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            t = (t + 1) % cq.size();
            cq[t] = value;
            size++;
            return true;
        }
        else
            return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
           h = (h + 1) % cq.size();
           size--;
           return true;
        }
        else
            return false;    
    }
    
    int Front() {
        return isEmpty() ? -1 : cq[h];    
    }
    
    int Rear() {
        return isEmpty() ? -1 : cq[t];    
    }
    
    bool isEmpty() {
        return size == 0;    
    }
    
    bool isFull() {
        return size == cq.size();        
    }
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
// @lc code=end

