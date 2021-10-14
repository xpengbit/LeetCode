/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        /*首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，
        如果右边的小盆友的等级高，等加一个糖果，这样保证了一个方向上高等级的糖果多。
        然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，
        则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可*/
        const size_t n = ratings.size();
        int total = 0;
        vector<int> res(n, 1);
        for(int i = 0; i < n - 1; ++i){
            if(ratings[i + 1] > ratings[i]) res[i + 1] = res[i] + 1;
        }
        for(int i = n - 1; i > 0; --i){
            if(ratings[i - 1] > ratings[i]) res[i - 1] = max(res[i - 1], res[i] + 1 );
        }
        for(int num : res){
            total += num;
        }
        return total;
    }
};
// @lc code=end

