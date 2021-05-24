/*
 * @lc app=leetcode id=895 lang=cpp
 *
 * [895] Maximum Frequency Stack
 */

// @lc code=start
class FreqStack {
    unordered_map<int, int> freq; /*value to frequence*/
    unordered_map<int, stack<int>> mp; /*frequence to most recent*/
    int maxFreq;
public:
    FreqStack() {
       maxFreq = 0; 
    }
    
    void push(int val) {
        freq[val]++;
        mp[freq[val]].push(val);
        maxFreq = max(maxFreq, freq[val]);    
    }
    
    int pop() {
        int tmp = mp[maxFreq].top();
        mp[maxFreq].pop();
        freq[tmp]--;
        if(mp[maxFreq].empty()) maxFreq--;
        return tmp;    
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

