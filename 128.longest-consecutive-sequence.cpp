/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //将所有的元素放入一个集合中．
        //然后我们再遍历一下这个数组nums[i]，如果nums[i]-1不在这个集合中，
        //说明nums[i]可能是一个连续序列的下限，那么我们就从这个下限顺着递增去查验，
        //找到一个完整的递增序列．如果nums[i]-1在这个集合中，说明它有更小的下限，
        //那么我们就不去查验这个递增序列，因为我们规定，只有遇到了下限才会去查验整个序列．
        //于是遍历完整个数组后，对于集合的查验也就仅仅是o(n)次．
        /*if(nums.size() == 0) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        for(int num : nums){
            if(s.find(num - 1) != s.end()) continue;
            int j = num + 1;
            while(s.find(j) != s.end())
                j++;  //这里j已经多加了一次。所以下面为 j- num
            res = max(res, j - num);
        }
        return res;*/

        if(nums.size() == 0) return 0;
        unordered_map<int, bool> mp;
        int res = 1;
        for(int num : nums) mp[num] = false;
        for(int num : nums){
            if(mp[num] == true) continue;
            int len = 1, pre = num - 1, next = num + 1;
            mp[num] = true;
            while(mp.count(pre)) {
                len++;
                mp[pre] = true;
                pre--;
            }
            while(mp.count(next)){
                len++;
                mp[next] = true;
                next++;
            }
            res = max(res, len);
        }
        return res;
    }
};
// @lc code=end

