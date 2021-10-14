/*
 * @lc app=leetcode id=679 lang=cpp
 *
 * [679] 24 Game
 */

// @lc code=start
class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(4);
        for(int i = 0; i < 4; ++i)
            nums[i] = (double)cards[i];

        sort(nums.begin(), nums.end());
        while(1){
            unordered_set<double> res = helper(nums, 0, 3);
            for(auto n : res){
                if(n - 24.0 < 1e-10)
                    return true;
            }

            if(next_permutation(nums.begin(), nums.end()) == false)
                break;
        }
        return false;    
    }
private:
    unordered_set<double> helper(vector<double>& nums, int start, int end){
        if(start == end) return {nums[start]};
        unordered_set<double> res;

        for(int i = start; i < end; ++i){
            unordered_set<double> A = helper(nums, start, i);
            unordered_set<double> B = helper(nums, i + 1, end);
            for(auto x : A){
                for(auto y : B){
                    res.insert(x + y);
                    res.insert(x - y);
                    res.insert(x * y);
                    if(y != 0)
                        res.insert(x / y);
                }
            }
        }
        return res;
    }
};
// @lc code=end

