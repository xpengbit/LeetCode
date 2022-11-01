#include <bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> a(n); //a[i].first = deviliery cost, a[i].second = item cost;
    for(int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
    sort(a.rbegin(), a.rend());
    priority_queue<int, vector<int>, greater<>> pq;
    int sum = 0, res = 0;
    for(auto [dcost, icost] : a){
        if(pq.size() == m){
            sum -= pq.top();
            pq.pop();
        }
        sum += icost;
        pq.push(icost);
        if(pq.size() == m)
            res = max(res, sum + m * dcost);
        else
            res = max(res, sum + pq.size() * dcost);
        
    }

    return res;
}

/*#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    pair<int,int> a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a, a + n);
    priority_queue<int,vector<int>, greater<int>> pq;
    int maxOfMSum = 0;
    for(int i = n - 1; i >= n - m; i--) {
        maxOfMSum += a[i].second;
        pq.push(a[i].first);
    }
    int ans = maxOfMSum + m * pq.top();
    for(int i = n - m - 1; i >= 0; i--) {
        if(a[i].second > pq.top()) {
            maxOfMSum += a[i].second - pq.top();
            pq.pop();
            pq.push(a[i].first);
        }
        ans = max(ans, m * pq.top());
    }
    cout << ans;*/
    // 3 2
    // 7 10
    // 4 15
    // 8 1
    // output
    // 31
    return 0;
}