/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int  l = 0, h = letters.size(), mid;
        char ch = letters[0];

        while(l < h){
            mid = l + (h-l)/2;
            if(letters[mid] > target){
                h = mid;
            }
            else
                l = mid + 1;
        }
        if(letters[l] > target) return letters[l];
        return ch;
    }
};
// @lc code=end

