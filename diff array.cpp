#inlcude <bits/stdc++.h>
using namespace std;

class difference{
    vector<int> diff;
    int n;
public:
    difference(vector<int>& nums){
        this->n = nums.size();
        diff = vector<int>(n, 0);
        diff[0] = nums[0];
        for(int i = 1; i < n; ++i)
            diff[i] = nums[i] - nums[i - 1];
    }

    //从差分数组恢复数组
    /*vector<int> res(n);
    res[0] = diff[0];
    for(int i = 1; i < n; ++i){
        res[i] = res[i - 1] + diff[i];
    } */

    //给闭区间[i, j] 增加value
    void increment(int i, int j, int val){
        diff[i] += val;
        if(j + 1 < diff.size())
            diff[j + 1] -= val;
    }

    //返回结果数组
    vector<int> result(){
        vector<int> res(n);
        res[0] = diff[0];
        for(int i = 1; i < n; ++)
            res[i] = res[i - 1] + diff[i];
        
        return res;
    }
}