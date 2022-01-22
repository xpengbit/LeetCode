/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

// @lc code=start
/*class Solution {
public:
    bool isNumber(string s) {
        int len = s.size();
        int left = 0, right = len - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisted = false;
        //delete space from front and end of the string
        while(s[left] == ' ') ++left;
        while(s[right] == ' ') --right;
        //if only have one char and not digit, return false
        if(left >= right && (s[left] < '0' || s[left] > '9')) return false;
        //process the first char
        if(s[left] == '.') dotExisted = true;
        else if(s[left] >= '0' && s[left] <= '9') digitExisted = true;
        else if(s[left] != '+' && s[left] != '-') return false;
        //process the middle char
        for(int i = left + 1; i <= right - 1; ++i){
            if(s[i] >= '0' && s[i] <= '9') digitExisted = true;
            else if(s[i] == 'E' || s[i] == 'e'){ //e,E cannot follow + or -, only digit
                if(!eExisted && s[i - 1] != '+' && s[i - 1] != '-' && digitExisted) eExisted = true;
                else return false;
            }
            else if(s[i] == '+' || s[i] == '-'){// +,- can only follow e
                if(s[i - 1] != 'e' && s[i - 1] != 'E') return false;
            }
            else if(s[i] == '.'){//. can only occur once and can not follow after e or E
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
};*/

class Solution {
public:
    bool isNumber(string s) {
        while(s.size() > 1 && s.back() == ' ') s.pop_back();
        while(s.size() > 1 && s[0] == ' ') s.erase(s.begin());
        if(s == "") return false;
        int cntE = 0, posE = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'E' || s[i] == 'e'){
                cntE++;
                posE = i;
            }   
        }
        if(cntE > 1) return false;
        if(cntE == 0) return isOk(s, 1);

        return isOk(s.substr(0, posE), 1) && isOk(s.substr(posE + 1), 0);
    }

    bool isOk(string s, int k){
        for(int i = 0; i < s.size(); ++i){
            if((s[i] == '+' || s[i] == '-') && i != 0)
                return false;
        }
        if(s[0] == '+' || s[0] == '-')
            s.erase(s.begin());
        if(s == "" || s == ".") return false;
        
        int cntDot = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '.') cntDot++;
            else if(!isdigit(s[i])) return false;
        }

        return cntDot <= k;
    }
};
// @lc code=end

