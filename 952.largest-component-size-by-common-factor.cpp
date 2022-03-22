/*
 * @lc app=leetcode id=952 lang=cpp
 *
 * [952] Largest Component Size by Common Factor
 */

// @lc code=start
class Solution {
    int L = 100000;
    int Father[100005];
public:
    int FindFather(int x){
        if(x != Father[x])
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }

    void Union(int x, int y){
        x = Father[x];
        y = Father[y];
        if(x < y) Father[y] = x;
        else Father[x] = y;
    }

    vector<int>Eratosthenes(int n)
    {
        auto q=vector<int>(n+1,0);
        for (int i=2; i<=sqrt(n); i++)
        {
            if (q[i]==0)
            {
                int j=i*2;
                while (j<n)
                {
                    q[j]=1;
                    j+=i;
                }
            }
        }
        vector<int>primes;
        for (int i=2; i<=n; i++)
        {
            if (q[i]==0)
                primes.push_back(i);                
        }
        return primes;
    }

    int largestComponentSize(vector<int>& nums) {
        for(int i = 0; i <= L; ++i)
            Father[i] = i;
        
        vector<int> prime = Eratosthenes(sqrt(L));

        for(int i = 0; i < nums.size(); ++i){
            int x = nums[i];
            for(int p : prime){
                if(x % p == 0){
                    if(FindFather(nums[i]) != FindFather(p))
                        Union(p, nums[i]);
                    while(x % p == 0) x /= p;
                }
            }

            if(x > 1){
                if(FindFather(nums[i]) != FindFather(x))
                    Union(nums[i], x);
            }
        }

        unordered_map<int, int> count;
        for(int i = 0; i < nums.size(); ++i)
            count[FindFather(nums[i])]++;
        int ret = 0;
        for(auto c : count)
            ret = max(ret, c.second);
        return ret;
    }
};
// @lc code=end

