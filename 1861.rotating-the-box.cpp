/*
 * @lc app=leetcode id=1861 lang=cpp
 *
 * [1861] Rotating the Box
 */

// @lc code=start
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int count = 0;
                int k = j;
                while(k < n && box[i][k] != '*'){
                    if(box[i][k] == '#') count++;
                    k++;
                }
                if(k != n)
                    res[k][m - 1 - i] = '*';
                j = k; //j 要从挡板的位置继续开始
                while(count > 0){
                    res[k - 1][m - 1 - i] = '#';
                    k--;
                    count--;
                }
            }
        }
        return res;    
    }
};
// @lc code=end
//记录下翻转前遇到每一个挡板前的石头的数目，反转以后在挡板位置上方式相应个数的石头。

