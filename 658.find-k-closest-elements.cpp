/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //PQ Solution
        /*priority_queue<pair<int, int>> pq;
        for(auto a : arr){
            pq.push({abs(x - a), a});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;*/

        //双指针
        /*int i = 0, j = arr.size() - 1;
        while(j - i >= k){
            int left = x - arr[i];
            int right = arr[j] - x;
            if(left == right) j--;
            else{
                if(left > right) i++;
                else j--;
            }
        }
        vector<int> res;
        while(i <= j){
            res.push_back(arr[i]);
            i++;
        }
        return res;*/

        //Binary Search
        int low = 0, hi = arr.size() - k;
        while(low < hi){
            int mid = low + (hi - low)/2;
            if(x - arr[mid] > arr[mid + k] - x)
                low = mid + 1;
            else
        }
        int low = 0, hi = arr.size() - k; //这里二分的是k window的起点。
        while(low < hi){
            int mid = low + (hi - low)/ 2;
            if(x - arr[mid] > arr[mid + k] - x) //这里window的长度是k + 1
                low = mid + 1;
            else
                hi = mid;
        }

        vector<int> res;
        for(int i = 0; i < k; ++i)
            res.push_back(arr[low + i]);
        return res;
    }
};
// @lc code=end
//这种求k个值得问题，可以想到用pq; 这个是一个sorted的队列。要利用到排序的性质，想到双指针， 或者binary search. 
