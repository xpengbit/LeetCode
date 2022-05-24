/*Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] 
(si < ei), find the minimum number of conference rooms required.
Example 1:

Input: 
[[0, 30],[5, 10],[15, 20]]
Output: 2
Example 2:
Input: [[7,10],[2,4]]
Output: 1
NOTE: input types have been changed on April 15, 2019.
Please reset to default code definition to get new method signature.*/


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
         map<int, int> mp;
         for(auto interval : intervals){
             mp[interval[0]] += 1;
             mp[interval[1] + 1] -= 1;
         }

        int res = 0, sum = 0;
         for(auto& [start, end] : mp){
             sum += end;
             res = max(res, sum);
         }
         return res;
    }
};