/*
 * @lc app=leetcode id=957 lang=cpp
 *
 * [957] Prison Cells After N Days
 */

// @lc code=start
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        int K = 0;
        for(int i = 0; i < 8; ++i)
            K |= cells[i] << i;   //数组元素通过右移或转成一个整数；
        int K0 = K;
        //找循环节
        unordered_map<int, int> Map;
        int t = 0;
        while(Map.find(K) == Map.end()){
            Map[K] = t;
            t++;
            K = (~((K>>1)^(K << 1))) & 126; //01111110
        }
        int S = Map[K];
        int L = t - S;
        if(N >= S)
            N = (N - S) % L + S;
        
        int M = K0;
        for(int i = 0; i < N; ++i)
            M = (~((M>>1)^(M << 1))) & 126;
        
        vector<int> ret(8,0);
        for(int i = 0; i < 8; ++i)
            ret[i] = (M >> i) & 1;

        return ret;
    }
};
// @lc code=end
//这个题考察位操作。cells由左边跟右边的值来决定。这样可以把cells左移一位，再右移一位。然后异或。取反。
//这题还有一个难点是要找到循环节，这样可以大大减少循环次数。

