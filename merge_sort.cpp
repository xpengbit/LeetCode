#incudle <bits/stdc++.h>

void merge(int s, int m, int e, vector<int>& nums){
    vector<int> v1, v2;
    for(int i = s; i <= m; ++i) v1.push_back(nums[i]);
    for(int i = m + 1; i <= e; ++i) v2.push_back(nums[i]);

    /*
    这是一个经典算法；求逆序对。
    可以在合并之前这里做一些事情：比如求一个数组元素之差小于等于某个值的情况；
    int i = 0, j = 0;
    while(j < v2.size()){
        while(i < v1.size() && v1[i] - d <= v2[j]) i++;
        j++;
        cnt += i;
    }

    这是很巧妙的一个想法。
    merge_sort是稳定的。所以不会出现重复。是一个NlogN 的解法。
    */
    int i = 0, j = 0, k = s;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] < v2[j]){
            nums[k++] = v1[i++];
        }
        else
            nums[k++] = v1[j++];
    }

    if(i == v1.size()){
        while(j < v2.size()){
            nums[k++] = v2[j++];
        }
    }
    if(j == v2.size()){
        while(i < v1.size()){
            nums[k++] = v1[j++];
        }
    }
}


void merge_sort(int s, int e, vector<int>& nums){
    if(s >= e) return;
    int m = (s + e) >> 1;
    merge_sort(s, m, nums);
    merge_sort(m + 1, e, nums);
    merge(s, m, e, nums);
}

