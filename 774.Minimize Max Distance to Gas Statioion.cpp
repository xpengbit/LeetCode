/*On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1], 
where N = stations.length.
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.
Example:
Input: stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], K = 9
Output: 0.500000
Note:
stations.length will be an integer in range [10, 2000].
stations[i] will be an integer in range [0, 10^8].
K will be an integer in range [1, 10^6].
Answers within 10^-6 of the true value will be accepted as correct.*/

//解法1: 二分搜值。先在最小值最大值之间猜一个。看看分成这样的大小需要的数量是不是超过K。超过了，间隔大一点；
//如果小于K,可以试试间隔再小一点。这里与普通的二分搜值不同的是用到了double;
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double left = 0, right = 0;
        for(int i = 1; i < stations.size(); ++i)
            right = fmax(right, stations[i] - stations[i - 1]);

        while(right - left > 1e-6){ //浮点数判断两数相等
            double mid = (left + right) / 2;
            int cnt = 0;
            for(int i = 1; i < stations.size(); ++i){
                double t = (stations[i] - stations[i - 1]) / mid;
                cnt += ceil(t) - 1;  //一个间隔分成3份；中间需要2个加油站；
            }

            if（cnt > k)
                left = mid;
            else
                right = mid;
        }

        return left;
    }
};


//解法2：贪心算法
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        prioirty_queue<pair<double, int>> pq;  //{space, parts}
        for(int i = 1; i < stations.size(); ++i)
            pq.push({(stations[i] - stations[i - 1]), 1});

        for(int i = 0; i < k; ++i){
            auto [space, parts] = pq.top();
            pq.pop();
            pq.push({(space * parts) / (parts + 1), parts + 1})
        }
        
        return pq.top().first;
    }
};

//上面的解法会TLE。优化后
class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int k) {
        double ub = (stations.back() - stations[0]) / (k + 1);
        prioirty_queue<pair<double, int>> pq;  //{space, parts}
        for(int i = 1; i < stations.size(); ++i){
            double dist = stations[i] - stations[i - 1];
            int t = fmax(1, dist / ub);
            pq.push({dist / t, t});
            k -= (t - 1);
        }

        while(k > 0){
            auto [space, parts] = pq.top();
            pq.pop();
            pq.push({(space * parts) / (parts + 1), parts + 1});
            k--;
        }
        
        return pq.top().first;
    }
};