/*
 * @lc app=leetcode id=732 lang=cpp
 *
 * [732] My Calendar III
 */

// @lc code=start
class MyCalendarThree {
public:
    MyCalendarThree() {
        res = 0;
        sum = 0;
    }
    
    int book(int start, int end) {
        mp[start] += 1;
        mp[end] -= 1;

        for(auto& [s, diff] : mp){
            sum += diff;
            res = max(res, sum);
        }
        return res;
    }

private:
    int res, sum;
    map<int, int> mp;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
// @lc code=end

