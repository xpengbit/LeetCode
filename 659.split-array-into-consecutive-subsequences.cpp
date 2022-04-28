/*
 * @lc app=leetcode id=659 lang=cpp
 *
 * [659] Split Array into Consecutive Subsequences
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> seq; //key: 序列最后一个元素的值。val: 序列的个数
        unordered_map<int, int> count; //key: 数组元素的值。 val: 元素的个数

        for(int x : nums)
            count[x]++;

        for(int x : nums){
            if(count[x] == 0) continue;
            
            if(seq[x - 1] > 0){
                seq[x]++;
                seq[x - 1]--;
                count[x]--;
            }
            else{
                if(!count[x + 1] || !count[x + 2])
                    return false;
                else{
                    seq[x + 2]++;
                    count[x]--;
                    count[x + 1]--;
                    count[x + 2]--;
                }
            }
        }
        return true;        
    }
};
// @lc code=end

//这个题是一个greedy. 如果已经有一个大于3的序列，则这个值就跟在序列的最后面。
//如果没有，则要看数组里还有没有 x+1, x+2, 如果没有，return false;
//数据结构的设计也很关键，unordered_map<int, int> seq 表示以key结尾的seq的个数。
//unordered_map<int, int> count 表示数组中各个元素的个数。

