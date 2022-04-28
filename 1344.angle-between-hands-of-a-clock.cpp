/*
 * @lc app=leetcode id=1344 lang=cpp
 *
 * [1344] Angle Between Hands of a Clock
 */

// @lc code=start
class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        double h = hour * 30 + minutes / 2.0;
        double m = minutes * 6;

        return min(abs(m - h), 360 - abs(m - h));     
    }
};
// @lc code=end
// @lc code=end
    // The approach is, we will calculate the angle between 12 to hour hand and 12 to minute hand
    // and take the difference between them
    // but while minute hand goes ahead hour hand also moves ahead so we need to calculate that small
    // angle also. It will be minutes/2
    // ex. 02 : 30
    // between every hour angle is 30 deg.
    // that extra angle will be calculated as 
    // minutes      angel
    //   60          30   with respect to hour hand (60 mins) ans is 30.
    //   m           ?
    //       30 * m
    // ans = -------     so it is m/2
    //          60
    
    // so total angle of hour hand from 12 will be hour*30 + minutes/2.0;
    // for angle bet 12 and minute hand 
    //   60          360
    //   m           ?
    
    // so minutes angle is m*6
    // for considering acute angle we will take    min(abs(m-h), 360-abs(m-h));
