/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisted = false;
        /*delete space from front and end of the string*/
        while(s[left] == ' ') ++left;
        while(s[right] == ' ') --right;
        /*if only have one char and not digit, return false*/
        if(left >= right && (s[left] < '0' || s[left] > '9')) return false;
        /*process the first char*/
        if(s[left] == '.') dotExisted = true;
        else if(s[left] >= '0' && s[left] <= '9') digitExisted = true;
        else if(s[left] != '+' && s[left] != '-') return false;
        /*process the middle char*/
        for(int i = left + 1; i <= right - 1; ++i){
            if(s[i] >= '0' && s[i] <= '9') digitExisted = true;
            else if(s[i] == 'E' || s[i] == 'e'){ /*e,E cannot follow + or -, only digit*/
                if(!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisted) eExisted = true;
                else return false;
            }
            else if(s[i] == '+' || s[i] == '-'){/* +,- can only follow e*/
                if(s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            }
            else if(s[i] == '.'){/*. can only occur once and can not follow after e or E*/
                if(!dotExisted && !eExisted) dotExisted = true;
                else return false;
            }
            else 
                return false;
        }  
        if(s[right] >= '0' && s[right] <= '9') return true;
        else if(s[right] == '.' && !dotExisted && !eExisted && digitExisted) return true;
        else return false;
    }
};
// @lc code=end

