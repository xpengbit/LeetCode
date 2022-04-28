/*
 * @lc app=leetcode id=1386 lang=cpp
 *
 * [1386] Cinema Seat Allocation
 */

// @lc code=start
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        int res = 0;
        unordered_map<int, int> rows;
        for(auto reserved : reservedSeats)
            rows[reserved[0]] |= (1 << (reserved[1] - 1));
        
        for(auto [row, seats] : rows){
            bool a = (~seats & 30) == 30;    //0000011110
            bool b = (~seats & 120) == 120;  //0001111000
            bool c = (~seats & 480) == 480;  //0111100000
            
            // If we have a or c - sides, we shouldn't consider b - middle
            res += (a && c) ? 2 : (a || c) ? 1 : b;
        }
        
        // add two for each row with no reserved seats
        res += (n - rows.size()) * 2;
        return res;
    }
};
// @lc code=end

