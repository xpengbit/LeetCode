/*
 * @lc app=leetcode id=331 lang=cpp
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int count = 0;
        for(int i = 0; i < n; ++i){
            if(preorder[i] != ',' && preorder[i] != '#'){
                while(i < n && preorder[i] != ',') ++i;
                count--;
            }
            else if(preorder[i] == '#'){
                count++;
                i++;
            }

            if(i < n - 1 && count > 0) return false;
        }

        if(count != 1) return false;
        return true;
    }
};
// @lc code=end

