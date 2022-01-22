/*
 * @lc app=leetcode id=373 lang=cpp
 *
 * [373] Find K Pairs with Smallest Sums
 */

// @lc code=start

//Binary Search by value.
/*class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long lower = nums1[0] + nums2[0], upper = nums1.back() + nums2.back();
        while(lower < upper){
            long mid = lower + (upper - lower) / 2;
            long cnt = countLowerandEqual(mid, nums1, nums2);
            if(cnt < k)
                lower = mid + 1;
            else
                upper = mid;
        }
        long m = lower;
        vector<vector<int>> res1;
        vector<vector<int>> res2;
        for(int i = 0; i < nums1.size(); ++i){
            int j = 0;
            while(j < nums2.size() && nums1[i] + nums2[j] <= m){
                if(nums1[i] + nums2[j] < m)
                    res1.push_back({nums1[i], nums2[j]});
                else
                    res2.push_back({nums1[i], nums2[j]});
                
                ++j;
            }
        }
        int t = min(res2.size(), k - res1.size());
        for(int i = 0; i < t; ++i){
            res1.push_back(res2[i]);
        }

        return res1;
    }
private:
    long countLowerandEqual(long m, vector<int>& nums1, vector<int>& nums2){
        long res = 0;
        int j = nums2.size() - 1;
        for(int i = 0; i < nums1.size(); ++i){
            while(j >= 0 && nums1[i] + nums2[j] > m)
                --j;
            res += j + 1;
        }
        return res;
    }
};
*/
class Solution {
    struct cmp{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int m = nums1.size(), n = nums2.size();
        if(m == 0 || n == 0) return res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        q.push({nums1[0] + nums2[0], 0});
        visited[0][0] = 1;
        int count = 0; 
        while(count < k && !q.empty()){
            int i = q.top().second / n ;
            int j = q.top().second % n;
            count++;
            res.push_back({nums1[i], nums2[j]});
            q.pop();

            if(i + 1 < m && j < n && visited[i + 1][j] == 0){
                q.push({nums1[i + 1] + nums2[j], (i + 1) * n + j});
                visited[i + 1][j] = 1;
            }
            if(i < m && j + 1 < n && visited[i][j + 1] == 0){
                q.push({nums1[i] + nums2[j + 1], i * n + j + 1});
                visited[i][j + 1] = 1;
            } 
        }
        return res;
    }
};
// @lc code=end

