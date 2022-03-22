/*
 * @lc app=leetcode id=630 lang=cpp
 *
 * [630] Course Schedule III
 */

// @lc code=start
class Solution {
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), cmp);
        int n = courses.size();
        priority_queue<int> pq;
        int t = 0;
        for(int i = 0; i < n; ++i){
            t += courses[i][0];
            pq.push(courses[i][0]);
            if(t > courses[i][1]){
                t -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
// @lc code=end
//Greedy + PQ; 先把课程按deadline排序，然后用一个priority queue（大顶）存储每一个课程用的时间。
//如果超过了deadline， pq弹出耗时最大的课程。总共能take的课程不变，但弹出最大后，总耗时减少。这是一个贪心的思想。 

