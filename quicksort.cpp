#include <bits/stdc++.h>

using namespace std;

class solution{
public:
    void quicksort(vector<int>& nums){
        int n = nums.size();
        qsort(nums, 0, n - 1);
    }

    void qsort(vector<int>& nums, int a, int b){
        if(a >= b) return;
        int piovt = partition(nums, a, b);
        qsort(nums, a, pivot - 1);
        qsort(nums, piovt + 1, b);
    }

    int partition(vector<int>& nums, int a, int b){
        int pivot = nums[a];
            while(a < b){
            while(a < b && nums[b] >= piovt) b--;
            nums[a] = nums[b];
            while(a < b && nums[a] <= pivot) a++;
            nums[b] = nums[a];
        }
        
        nums[a] = pivot;
        return a;
    }
};