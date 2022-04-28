/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start
class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;        
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end())  return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;    
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);
        l.push_front({key, value});
        m[key] = l.begin();
        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }    
    }

private:
    int cap;
    list<pair<int,int>> l;
    unordered_map<int, list<pair<int,int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

