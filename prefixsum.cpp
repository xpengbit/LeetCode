#include <bits/stdc++.h>
using namespace std;

class prefixSum{
private:
    vector<int> sum;
public:
    vector<int> prefixSum(vector<int>& nums){
        int n = nums.size();
        sum.resize(n + 1);
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        return sum;
    }

    int query(int i, int j){
        return sum[j + 1] - sum[i];
    }
}