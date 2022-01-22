/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int res = 0;
        for(int i = 0; i < points.size(); ++i){
            unordered_map<int, int> mp;
            int sameCount = 0;
            for(int j = 0; j < points.size(); ++j){
                if(i == j) continue;
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                    sameCount++;
                    continue;
                }

                int flag = 0;
                for(auto t : mp){
                    if ((long long)(points[t.first][1]-points[i][1])*(points[j][0]-points[i][0]) == (long long)(points[j][1]-points[i][1])*(points[t.first][0]-points[i][0])){
                        flag = 1;
                        mp[t.first]++;
                        break;     
                    }
                }

                if(flag == 0)
                    mp[j] = 1;
            }

            int tmp = 0;
            for(auto t : mp){
                tmp = max(tmp, t.second);
            }
            tmp += (sameCount + 1);
            res = max(res, tmp);
        }
        return res;
    }
};
// @lc code=end

