第一章 编程技巧

判断两个浮点数a和b是否相等， 不用a == b. 应该判断两者之差的绝对值小于某一个阈值。fabs(a - b) < 1e-9.
判断某个数是否为奇数。x % 2 != 0, 不用 x % 2 == 1. 因为 x 有可能为负数。
vector和string 优先于动态分配的数组。

第二章 线性表

2.1 数组
2.1.1 Remove Duplicates from Sorted Array (26)
/*时间复杂度O(n),空间复杂度O(1)*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int index = 0;
        for(int i = 1; i < nums.size(); ++i>){
            if(nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index + 1;
    }
}

Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int cur = 0, index = 0;
        while(cur < nums.size()){
            if(nums[index] == nums[cur]) cur++;
            else nums[++index] == nums[cur++];
        }
        return nums.empty() ? 0 : index + 1;
    }
}


/*使用STL，时间复杂度O(n),空间复杂度O(1)*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        return distance(nums.begin(), unique(nums.begin(), nums.end()));
    }
}

Remove Element (27)
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for(int i = 0; i < nums.size(); ++i)
            if(nums[i] != val)
                nums[index++] = nums[i];        
        
        return res;
    }
};

Remove Duplicate Letters (316)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> visited(256);
        vector<int> cnt(256);
        string res = "0";
        for(char c : s)  ++cnt[c];
        for(char c : s){
            --cnt[c];
            if(visited[c]) continue;
            while(c > res.back() && cnt[res.back()]){
                visited[res.back()] = 0;
                res.pop_back();
            }
            res += c;
            visited[c] = 1;
        }
        return res.substr(1);        
    }
};


2.1.2 Remove Duplicates from Sorted Array II  (80)
/*上一题的follow up 最多允许两个重复*/
Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        if(nums.size() <= 2>) return nums.size();
        int index = 2;
        for(int i = 2; i < nums.size(); ++i){
            if(nums[i] != nums[index - 2])
                nums[index++] = nums[i];
        }
        return index;
    }
}

Class Solution{
public:
    int removeDuplicates(vector<int>& nums){
        int n = nums.size();
        int index = 0;
        for(int i = 0; i < n; ++i){
            if(i > 0 && i < n - 1 && nums[i - 1] == nums[i] && nums[i + 1] == nums[i])
                continue;
            nums[index++] = nums[i];
        }
        return index; 
    }
}

2.1.3 Search in Rotated Sorted Array  (33)

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Class Solution{
public:
    int search(const vector<int>& nums, int target){
        /*int left = 0, right = nums.size();
        while(left != right){
            const int mid = left + (right - left)/2;
            if(nums[mid] == target) return mid;
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[right - 1])
                    left = mid + 1;
                else
                    right = mid;
            }
        }
        return -1;*/

        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] == target) return mid;
            else if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid])
                    r = mid;
                else
                    l = mid + 1;
            }
            else{
                if(nums[mid] < target && target <= nums[r - 1])
            }
        }
    }
}

2.1.4 Search in Rotated Sorted Array II  (81)
Follow up for 2.1.3, what if duplicates are allows?

Class Solution{
public:
    bool search(const vector<int>& nums, int target){
        if(nums.empty()) return false;
        int left = 0, right = nums.size();
        while(left < right){
            const int mid = left + (right - left)/2;
            if(nums[mid] == target) return true;
            if(nums[left] < nums[mid]){
                if(nums[left] <= target && nums[mid] > target)
                    right = mid;
                else
                    left = mid + 1;
            }
            else if(nums[left] > nums[mid]){
                if(nums[mid]< target && nums[right - 1] >= target)
                    left = mid + 1;
                else
                    right = mid;
            }
            else
                left++;
        }
        return false;
    }

2.1.5 Median of Two Sorted Arrays  (4)
/*中位数需要判断长度是奇数or偶数*/
/*首先，为了避免拷贝产生新的数组从而增加时间复杂度，使用两个变量i和j分别来标记数组 nums1 和 nums2 的起始位置。然后来处理一些 corner cases，比如当某一个数组的起始位置大于等于其数组长度时，说明其所有数字均已经被淘汰了，相当于一个空数组了，那么实际上就变成了在另一个数组中找数字，直接就可以找出来了。还有就是如果 K=1 的话，只要比较 nums1 和 nums2 的起始位置i和j上的数字就可以了。难点就在于一般的情况怎么处理？因为需要在两个有序数组中找到第K个元素，为了加快搜索的速度，可以使用二分法，那么对谁二分呢，数组么？其实要对K二分，意思是需要分别在 nums1 和 nums2 中查找第 K/2 个元素，注意这里由于两个数组的长度不定，所以有可能某个数组没有第 K/2 个数字，所以需要先 check 一下，数组中到底存不存在第 K/2 个数字，如果存在就取出来，否则就赋值上一个整型最大值（目的是要在 nums1 或者 nums2 中先淘汰 K/2 个较小的数字，判断的依据就是看 midVal1 和 midVal2 谁更小，但如果某个数组的个数都不到 K/2 个，自然无法淘汰，所以将其对应的 midVal 值设为整型最大值，以保证其不会被淘汰），若某个数组没有第 K/2 个数字，则淘汰另一个数组的前 K/2 个数字即可。举个例子来说吧，比如 nums1 = {3}，nums2 = {2, 4, 5, 6, 7}，K=4，要找两个数组混合中第4个数字，则分别在 nums1 和 nums2 中找第2个数字，而 nums1 中只有一个数字，不存在第二个数字，则 nums2 中的前2个数字可以直接跳过，为啥呢，因为要求的是整个混合数组的第4个数字，不管 nums1 中的那个数字是大是小，第4个数字绝不会出现在 nums2 的前两个数字中，所以可以直接跳过。*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size(), n = nums2.size();
        int total = m + n;
        if(total & 0x1)
            return findKth(nums1, 0, nums2, 0, total/2 + 1);
        else
            return (findKth(nums1, 0, nums2, 0, total/2) + findKth(nums1, 0, nums2, 0, total/2 + 1))/2.0;
    }
preivate:
    static int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k){
        if(i >= nums1.size()) return nums2[j + k - 1];
        if(j >= nums2.size()) return nums1[i + k - 1];
        if(k == 1) return min(nums1[i], nums2[j]);
        int midVal1 = (i + k/2 -1 < nums1.size()) ? nums1[i + k/2 -1] : INT_MAX;
        int midVal2 = (j + k/2 -1 < nums2.size()) ? nums2[j + k/2 -1] : INT_MAX;
        if(midVal1 < midVal2)
            return findKth(nums1, i + k/2, nums2, j, k - k/2);
        else
            return findKth(nums1, i, nums2, j + k/2, k - k/2);
    }

2.1.6 Longest Consecutive Sequence(128)
/*如果是nlogn 的时间复杂度，可以先排序，然后遍历找出连续的子序列
由于序列里的元素是无序的，想到用hashmap*/
class Solution{
public:
    int longestConsecutive(const vector<int>& nums){
        if(nums.empty()) return 0;
        unordered_map<int, bool> used;
        int longest = 0;
        for(auto i : nums) used[i] = false;
        for(auto i : nums){
            if(used[i]) continue;
            int length = 1;
            used[i] = true;
            for(int j = i + 1; used.find(j) != used.end(); ++j){
                used[j] = true;
                length++;
            }
            for(int j = i - 1; used.find(j) != used.end(); --j){
                used[j] = true;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
}
/*Hashset 解法*/
class Solution{
public:
    int longestConsecutive(const vector<int>& nums){
        /*int res = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for(auto val : nums){
            if(!s.count(val)) continue;
            s.erase(val);
            int next = val + 1, pre = val - 1;
            while(s.count(pre)) s.erase(pre--);
            while(s.count(next)) s.erase(next++);
            res = max(res, next - pre -1);  
        }
        return res;*/

        int res = 0;
        unordered_set<int> Set(nums.begin(), nums.end());
        for(int num : nums){
            if(Set.count(num - 1)) continue;
            int nxt = num + 1;
            while(Set.count(nxt))
                nxt++;
            res = max(res, nxt - num);
        }
        resturn res;
    }
}

2.1.7 Two Sum (1)
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); ++i>){
            int diff = target - num[i];
            if(m.count(diff)) return {m[diff], i};
            m[nums[i]] = i; 
        }
        return {};   
    }
}

2.1.8 3Sum (15)
class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() < 3 || nums.front() > 0 || nums.back() < 0) return {};
        for(int k = 0; k < nums.size() - 2; ++k){
            if(nums[k] > 0) break;
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while(i < j){
                if(nums[i] + nums[j] == target){
                    res.push_back({nums[k], nums[i], nums[j]});
                    while(i < j && nums[i] == nums[i + 1]) ++i;
                    while(i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                }
                else if(nums[i] + nums[j] < target)
                    ++i;
                else
                    --j;
            }
        }
        return res;
    }
}

2.1.9 3Sum Colsest (16)
class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        if(nums.empty() || nums.size() < 3) return 0;
        int closest = 0;
        int diff = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size() - 2; ++k){
            int i = k + 1, j = nums.size() - 1;
            while(i < j){
                int sum = nums[k] + nums[i] + nums[j];
                int newdiff = abs(sum - target);
                if(newdiff < diff){
                    diff = newdiff;
                    closest = sum;
                }
                if(sum < target) i++;
                else j--;
            }   
        }
        return closest;
    }
}

2.1.10 4Sum (18)

先排序，然后两个for loop固定下来两个数，再用i，j从头和尾扫。如果相等把结果存下来。
for循环的过程中需要判断是否有重复元素。
class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        if(nums.empty() || nums.size < 4) return {};
        vector<vector<int>> res;
        //set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size() - 3; ++k){
            if(k > 0 && nums[k - 1] == nums[k]) continue;
            for(int l = k + 1; l < nums.size() - 2; ++l){
                if(l > k + 1 && nums[l - 1] == nums[l]) continue;
                int i = l + 1, j = nums.size() - 1;
                while(i < j){
                    long sum = (long)nums[k] + nums[l] + nums[i] + nums[j];
                    if(sum == target){
                        /*
                        vector<int> tmp{nums[k], nums[g], nums[i], nums[j]};
                        res.insert(tmp);
                        ++i; --j;
                        */
                        res.push_back({nums[k],nums[l],nums[i],nums[j]});
                        while(i < j && nums[i] == nums[i + 1]) ++i;
                        while(i < j && nums[j] == nums[j - 1]) --j;
                        ++i; --j;
                    }
                    else if(sum < target) ++i;
                    else --j;
                }
            }
        }
        return res;
    }
}

2.1.11 Remove Element (27)
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.


class Solution{
public:
    int removeElement(vector<int>& nums, int target){
        int index = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != target)
                nums[index++] = nums[i];
        }
        return index;
    }
}

2.1.12 Next Permutation (31)

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

思路：先从右到左找到第一个不是递增的元素i，然后从右到左找到第一个大于i的元素j，交换之。然后把i到末尾的元素反转。

class Solution{
public:
    void nextPermutation(vector<int>& nums){
        if(nums.empty()) return;
        int n = nums.size();
        for(int i = n - 2; i >=0; --i){
            if(nums[i] < nums[i + 1]){
                int j;
                for(j = n - 1; j > i; --j){
                    if(nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
}

2.1.13 Permutation Sequence (60)

这道题是让求出n个数字的第k个排列组合，由于其特殊性，我们不用将所有的排列组合的情况都求出来，然后返回其第k个，这里可以只求出第k个排列组合即可，那么难点就在于如何知道数字的排列顺序，首先要知道当 n = 3 时，其排列组合共有 3! = 6 种，当 n = 4 时，其排列组合共有 4! = 24 种，这里就以 n = 4, k = 17 的情况来分析，所有排列组合情况如下：

1234
1243
1324
1342
1423
1432
2134
2143
2314
2341
2413
2431
3124
3142
3214
3241
3412 <--- k = 17
3421
4123
4132
4213
4231
4312
4321

可以发现，每一位上 1,2,3,4 分别都出现了6次，当最高位上的数字确定了，第二高位每个数字都出现了2次，当第二高位也确定了，第三高位上的数字都只出现了1次，当第三高位确定了，那么第四高位上的数字也只能出现一次，下面来看 k = 17 这种情况的每位数字如何确定，由于 k = 17 是转化为数组下标为 16：

最高位可取 1,2,3,4 中的一个，每个数字出现 3！= 6 次（因为当最高位确定了，后面三位可以任意排列，所以是 3！，那么最高位的数字就会重复 3！次），所以 k = 16 的第一位数字的下标为 16 / 6 = 2，在 "1234" 中即3被取出。这里的k是要求的坐标为k的全排列序列，定义 k' 为当最高位确定后，要求的全排序列在新范围中的位置，同理，k'' 为当第二高为确定后，所要求的全排列序列在新范围中的位置，以此类推，下面来具体看看：

第二位此时从 1,2,4 中取一个，k = 16，则此时的 k' = 16 % (3!) = 4，注意思考这里为何要取余，如果对这 24 个数以6个一组来分，那么 k=16 这个位置就是在第三组（k/6 = 2）中的第五个（k%6 = 4）数字。如下所示，而剩下的每个数字出现 2！= 2 次，所以第二数字的下标为 4 / 2 = 2，在 "124" 中即4被取出。

3124
3142
3214
3241
3412 <--- k' = 4
3421

第三位此时从 1,2 中取一个，k' = 4，则此时的 k'' = 4 % (2!) = 0，如下所示，而剩下的每个数字出现 1！= 1 次，所以第三个数字的下标为 0 / 1 = 0，在 "12" 中即1被取出。

3412 <--- k'' = 0
3421

第四位是从2中取一个，k'' = 0，则此时的 k''' = 0 % (1!) = 0，如下所示，而剩下的每个数字出现 0！= 1 次，所以第四个数字的下标为 0 / 1= 0，在 "2" 中即2被取出。

class solution{
public:
    string getPermutation(int n, int k){
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for(int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        k--;
        for(int i = n; i >= 1; --i){
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res; 
    }
}


2.1.14 Valid Sudoku (36)
Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

class Solution{
public:
    bool isValidSudoku(vector<vector<char>>& board){
        vector<bool> visited(9);
        for(int i = 0; i < 9; ++i){
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j)
                if(!check(board[i][j], visited)) return false;
            
            fill(visited.begin(), visited.end(), false);
            for(int j = 0; j < 9; ++j)
                if(!check(board[j][i], visited)) return false;
        }

        for(int r = 0; r < 3; ++i){
            for(int c = 0; c < 3; ++c){
                fill(visited.begin(), visited.end(), false);
                for(int i = r * 3; i < r * 3 + 3; ++i){
                    for(int j = c * 3; j < c * 3 + 3; ++j){
                        if(!check(board[i][j], visited)) return false;
                    }
                }
            }
        }
        return true;
    }
private:
    bool check(char ch, vector<bool>& visited){
        if(ch == '.') return true;
        if(visited[ch - '1']) return false;  /*注意这里 ch - '1'. 因为数组定义为0--8*/
        return visited[ch - '1'] = true;
    }
}

2.1.15 Trapping Rain Water (42)
先从左往右扫找到每一个点左边的最大值， 然后从右往左扫找到右边的最大值。取小的。然后减去当前点的高度。
class Solution{
public:
    int trap(vector<int>& height){
        int res = 0, n = height.size();
        vector<int> leftMaxHeight(n);
        vector<int> rightMaxHegiht(n);
        
        for(int i = 1; i < n; ++i){
            leftMaxHeight[i] = max(leftMaxHeight[i - 1], height[i - 1]);
            rightMaxHeight[n - 1 - i] = max(rightMaxHeight[n -i], height[n - i]); 
        }

        for(int i = 0; i < n; ++i){
            int h = min(leftMaxHeihgt[i], rightMaxHeight[i]);
            if(h > height[i])
                res += h - height[i];
        }
        return res;

    }
}

/*解法2-单调栈*/
/*遍历高度，如果此时栈为空，或者当前高度小于等于栈顶高度，则把当前高度的坐标压入栈，
注意这里不直接把高度压入栈，而是把坐标压入栈，这样方便在后来算水平距离。当遇到比栈顶高度大的时候，
就说明有可能会有坑存在，可以装雨水。此时栈里至少有一个高度，如果只有一个的话，那么不能形成坑，直接跳过，
如果多于一个的话，那么此时把栈顶元素取出来当作坑，新的栈顶元素就是左边界，当前高度是右边界，只要取二者较小的，
减去坑的高度，长度就是右边界坐标减去左边界坐标再减1，二者相乘就是盛水量**/
        stack<int> s;
        int res = 0, n = height.size(), i = 0;
        while(i < n){
            if(s.empty() || height[s.top()] >= height[i]){
                s.push(i++);
            }
            else{
                int t = s.top(); s.pop();
                if(s.empty()) continue;
                res += (min(height[s.top()], height[i]) - height[t]) * (i - s.top() - 1);
            }
        }
        return res;
    }

2.1.16 Rotate Image (48)
You are given an n x n 2D matrix representing an image.
Rotate the image by 90 degrees (clockwise).
Note:
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

class Solution{
public:
    void rotate(vector<vector<int>>& matrix){
        int n = matrix.size();
        for(int i = 0; i < n/2; ++i){
            for(int j = i; j < n - 1- i; ++j){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 -i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1- i] = tmp;
            }
        }
    }
}

还有一种解法，首先以从对角线为轴翻转，然后再以x轴中线上下翻转即可得到结果，如下图所示(其中蓝色数字表示翻转轴)：
1  2  3　　　 　　 9  6  3　　　　　     7  4  1

4  5  6　　-->　　 8  5  2　　 -->   　 8  5  2　　

7  8  9 　　　 　　7  4  1　　　　　     9  6  3
 

解法二：

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i; ++j) {
                swap(matrix[i][j], matrix[n - 1- j][n - 1 - i]);
            }
        }
        reverse(matrix.begin(), matrix.end());
    }
};

最后再来看一种方法，这种方法首先对原数组取其转置矩阵，然后把每行的数字翻转可得到结果，如下所示（其中蓝色数字表示翻转轴，
1  2  3　　　 　　 1  4  7　　　　　     7  4  1

4  5  6　　-->　　 2  5  8　　 -->  　  8  5  2　　

7  8  9 　　　 　　3  6  9　　　　       9  6  3
 

解法三：
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

2.1.17 Plus One(66)
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
You may assume the integer does not contain any leading zero, except the number 0 itself.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) return {};
        int n = digits.size();
        int c = 1;
        for(int i = n - 1; i >= 0; --i){
            int num = digits[i] + c;
            c = num / 10;
            digits[i] = num % 10;
            if(c == 0) break;
        }
        if(c > 0) digits.insert(digits.begin(), 1);
        return digits;   
    }
};

2.1.18 Climbing Stairs  (70)
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int climbStairs(int n) {
        /*if(n < 3) return n;
        vector<int> dp(n + 1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <=n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];*/

        memo = vector<int>(n + 1, 0);
        return helper(n);
        
private:
    vector<int> memo;
    int helper(int n){
        if(n <= 2) return n;
        if(memo[n] != 0) return memo[n];
        return memo[n] = helper(n - 1) + helper(n - 2);
    }
};

2.1.19 Gray Code  (89)
The gray code is a binary numeral system where two successive values differ in only one bit.
Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
00 - 0
01 - 1
11 - 3
10 - 2
// Binary to grey code
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        for (int i = 0; i < pow(2,n); ++i) {
            res.push_back((i >> 1) ^ i);
        }
        return res;
    }
};

/*Mirror Arrangement*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res{0};
        for(int i = 0; i < n; ++i){
            int m = res.size();
            for(int j = m - 1; j >= 0; --j){
                res.push_back(res[j] | 1 << i);
            }
        }
        return res;    
    }
};


2.1.20 Set Matrix Zeros (73)
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.
/*方法1，申请两个数组代表行，列； 如果有0，置为true.再遍历行，列，如果为true，置整行，整列为0*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        vector<bool> row(m, false);
        vector<bool> col(n, false);

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(matrix[i][j] == 0){
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for(int i = 0; i < m; ++i){
            if(row[i])
                fill(matrix[i].begin(), matrix[i].end(), 0);
        }
        for(int j = 0; j < n; ++j){
            if(col[j]){
                for(int i = 0; i < m; ++i)
                    matrix[i][j] = 0;
            }
        }        
    }
}

/*方法2：利用第一行，第一列。先保留第一行第一列状态（是否有0）。然后从第二行第二列开始遍历matrix，如果有0， 置第一行，第一列为0，再遍历一次，如果第一行第一列相应位置为0，则置matrix[i][j] = 0. 最后根据预先保留的标志位设置第一行，第一列。这个方法的空间复杂度为 O(1)*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        const size_t n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for(int i = 0; i < m; ++i){
            if(matrix[i][0] == 0) firstCol = true;
        }
        for(int j = 0; j < n; ++j){
            if(matrix[0][j] == 0) firstRow = true;
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;
            }
        }
        if(firstRow == true){
            for(int j = 0; j < n; ++j) matrix[0][j] = 0;
        }
        if(firstCol == true){
            for(int i = 0; i < m; ++i) matrix[i][0] = 0;
        }
    }
};

2.1.21 Gas Station (134)
我们首先要知道能走完整个环的前提是gas的总量要大于cost的总量，这样才会有起点的存在。假设开始设置起点start = 0, 
并从这里出发，如果当前的gas值大于cost值，就可以继续前进，此时到下一个站点，剩余的gas加上当前的gas再减去cost，
看是否大于0，若大于0，则继续前进。当到达某一站点时，若这个值小于0了，则说明从起点到这个点中间的任何一个点都不能作为起点，
则把起点设为下一个点，继续遍历。当遍历完整个环时，当前保存的起点即为所求。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const size_t n = gas.size();
        int sum = 0, total = 0, start = 0;
        for(int i = 0; i < n; ++i){
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0){
                start = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : start;
    }
};

2.1.22 Candy (135)  这个题与 1840， 1846 类似。 采用two-pass distribution

There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

class Solution {
public:
    int candy(vector<int>& ratings) {
        /*首先初始化每个人一个糖果，然后这个算法需要遍历两遍，第一遍从左向右遍历，
        如果右边的小盆友的等级高，增加一个糖果，这样保证了一个方向上高等级的糖果多。
        然后再从右向左遍历一遍，如果相邻两个左边的等级高，而左边的糖果又少的话，
        则左边糖果数为右边糖果数加一。最后再把所有小盆友的糖果数都加起来返回即可*/
        const size_t n = ratings.size();
        int total = 0;
        vector<int> res(n, 1);
        for(int i = 1; i < n - 1; ++i){
            if(ratings[i] > ratings[i - 1]) 
                res[i] = res[i - 1] + 1;
        }
        for(int i = n - 2; i >= 0; --i){
            if(ratings[i] > ratings[i + 1]) 
                res[i] = max(res[i], res[i + 1] + 1 );
        }
        
        total = accumulate(res.begin(), res.end(), 0);
        return total;


2.1.23 Single Number (136)
Given an array of integers, every element appears twice except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory?

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*使用异或。只要是偶数次，都可以清零*/
        int x = 0;
        for(auto num : nums)
            x ^= num;
        return x;

        /*return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());*/
    }
};

2.1.24 Single Number II (137)
Given an array of integers, every element appears three times except for one. Find that single one.
Note: Your algorithm should have a linear runtime complexity. Could you implement it without using
extra memory?

/*这道题就是除了一个单独的数字之外，数组中其他的数字都出现了三次，还是要利用位操作 Bit Manipulation 来解。
可以建立一个 32 位的数字，来统计每一位上1出现的个数，如果某一位上为1的话，那么如果该整数出现了三次，对3取余为0，
这样把每个数的对应位都加起来对3取余，最终剩下来的那个数就是单独的数字。*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int sum = 0;
            for (int j = 0; j < nums.size(); ++j) {
                sum += (nums[j] >> i) & 0x1;
            }
            res |= (sum % 3) << i;
        }
        return res;
    }
};




2.2 单链表
单链表节点定义如下：
struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x) : val = x, next(nullptr){}
};

2.2.1 Add Two Numbers (2)
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse
order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * Dummy = new ListNode(0);
        ListNode * cur = Dummy;
        int carrier = 0;

        while(l1 != NULL || l2 != NULL || carrier > 0){
            int num = carrier;
            if(l1 != NULL){
                num += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                num += l2->val;
                l2 = l2->next;
            }

            cur->next = new ListNode(num % 10);
            cur = cur->next;
            carrier = num / 10;
        }
        return Dummy->next;
    }
}

2.2.2 Reverse Linked List II (92)
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example: Given 1->2->3->4->5->nullptr, m = 2 and n = 4,
return 1->4->3->2->5->nullptr.
Note: Given m, n satisfy the following condition: 1 ≤ m ≤ n ≤ length of list.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        /*if(head == NULL || left == right) return head;
        ListNode* Dummy = new ListNode(-1, head);
        ListNode* cur = Dummy->next, *pre = Dummy;
        int i = 1;
        while(i < left){
            cur = cur->next;
            pre = pre->next;
            i++;
        } 
        ListNode* node = pre;
        while(i++ <= right){
            ListNode* n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }
        node->next->next = cur;
        node->next = pre;

        return Dummy->next;*/

        /*另外一种反转方法，以此把要反转的元素插入pre的后面*/
        ListNode* Dummy = new ListNode(-1, head);
        ListNode* pre = Dummy;
        int i = 1;
        while(i < left) {
            pre = pre->next;
            i++;
        }
        ListNode* cur = pre->next;
        while(i++ < right){
            ListNode* t = cur->next;
            cur->next = t->next;
            t->next = pre->next;
            pre->next = t;
        }

        return Dummy->next;
    }

    ListNode* reverse(ListNode* root){
        ListNode* pre = NULL, *cur = root, *nxt;
        while(cur){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = cur->next;
        }
        reuturn pre;
    }
};


2.2.3 Partition List (86)
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater
than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.
For example, Given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lDummy = new ListNode(-1);
        ListNode* gDummy = new ListNode(-1);
        ListNode* less = lDummy;
        ListNode* greater = gDummy;
        ListNode* cur = head;

        while(cur != NULL){
            if(cur->val < x){
                less->next = cur;
                less = less->next;
            }
            else{
                greater->next = cur;
                greater = greater->next;
            }
            cur = cur->next;
        }

        greater->next = nullptr;
        less->next = gDummy->next;

        return lDummy->next;
    }
};


2.2.4 Remove Duplicates from Sorted List (83)
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        for(ListNode* pre = head, *cur = pre->next; cur; cur = pre->next){
            if(pre->val == cur->val){
                pre->next = cur->next;
            }
            else
                pre = cur;
        }
        return head;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* cur = head;
        while(cur){
            while(cur->next != NULL && cur->val == cur->next->val)
                cur->next = cur->next->next;
            cur = cur->next;
        }
        return head;
    }
};


2.2.5 Remove Duplicates from Sorted List II (82)
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers
from the original list.
For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* Dummy = new ListNode(-1, head);
        Dummy->next = head;
        ListNode* pre = Dummy, *cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->val == cur->next->val){
                int tmp = cur->val;
                while(cur != NULL && cur->val == tmp) cur = cur->next;
                pre->next = cur;
            }
            else{
                cur = cur->next;
                pre = pre->next;
            }
        }

        return Dummy->next;
    }
};


2.2.6 Rotate List  
Given a list, rotate the list to the right by k places, where k is non-negative.
For example: Given 1->2->3->4->5->nullptr and k = 2, return 4->5->1->2->3->nullptr.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) retur head;
        int len = listLength(head);
        len = k % len;
        for(int i = 0; i < len; ++i)
            head = deleteTail(head);
        return head;    
    }
private:
    int listLength(ListNode* head){
        ListNode* cur = head;
        int length = 0;
        while(cur != NULL){
            length++;
            cur = cur->next;
        }
        return length;
    }

    ListNode* deleteTail(ListNode* head){
        ListNode* cur = head;
        while(cur->next->next != NULL) cur = cur->next;
        ListNode* nx = cur->next;
        cur->next = NULL;
        nx->next = head;
        head = nx;
        return head;
    }
};

/*解法2： 遍历链表得到长度。然后把尾跟头相接。再往后走 n - k% n 步*/
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        if(head == NULL || k == 0) return head;
        ListNode* cur = head;
        int len = 1;
        while(cur->next){
            len++;
            cur = cur->next;
        }
        cur->next = head;
        int n = len - k % len;
        for(int i = 0; i < n; ++i){
            cur = cur->next;
        }
        ListNode* newhead = cur->next;
        cur->next = NULL;
        return newhead;
    }
}

/*解法3： 使用快慢指针。 fast先走k步(k 要先 % n)。然后快慢同时走。快指针到达末尾时，慢指针的next就是新的头。*/


2.2.7 Remove Nth Node From End of List (19)
Given a linked list, remove the nth node from the end of list and return its head.
For example, Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
• Given n will always be valid.
• Try to do this in one pass.

/*首先要考虑的是，如何找到倒数第N个节点，由于只允许一次遍历，所以不能用一次完整的遍历来统计链表中元素的个数，而是遍历到对应位置就应该移除了。
那么就需要用两个指针来帮助解题，pre 和 cur 指针。首先 cur 指针先向前走N步，如果此时 cur 指向空，说明N为链表的长度，则需要移除的为首元素，
那么此时返回 head->next 即可，如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur 为最后一个元素时停止，此时 pre 指向要移除元素的前一个元素，
再修改指针跳过需要移除的元素即可*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL) return NULL;
        ListNode* fast = head, *slow = head;
        for(int i = 1; i <= n； ++i) fast = fast->next;
        if(!fast) return head->next; /*此时n为list长度。删除头，返回第二个元素*/
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};


2.2.8 Swap Nodes in Pairs (24)
Given a linked list, swap every two adjacent nodes and return its head.
You may not modify the values in the list's nodes, only nodes itself may be changed.
Example:
Given 
1->2->3->4
, you should return the list as 
2->1->4->3

/*方法1：iterative*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* Dummy = new ListNode(-1), *pre = Dummy;
        Dummy->next = head;
        while(pre->next && pre->next->next ){
            ListNode* t = pre->next->next;
            pre->next->next = t->next;
            t->next = pre->next;
            pre->next = t;
            pre = t->next;
        }
        return Dummy->next;
    }
};
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* Dummy = new ListNode(-1);
        Dummy->next = head;
        ListNode* pre = Dummy, *cur = head;
        while(cur != NULL && cur->next = NULL){
            ListNode* next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            pre = cur;
            cur = cur->next;
        }
        
        return Dummy->next;
    }
};

/*方法2： 递归*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* t = head->next;
        head->next = swapParis(head->next->next);
        t->next = head;
        return t;
    }
}


2.2.9 Reverse Node in K-Group (25)
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.
Only constant memory is allowed.
For example, Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

/*方法1：迭代法*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy, *cur = dummy->next;
        int num = 1;
        while(cur = cur->next) ++num;
        while(num >= k){
            cur = pre->next;
            for(int i = 1; i < k; ++i){
                ListNode* t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
            }
            num -= k;
            pre = cur;
        }
        return dummy->next;
    }
};

/*方法2：递归解法*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = head;
        for(int i = 0; i < k; ++i){
            if(!cur) return head;
            cur = cur->next;
        }
        ListNode* new_head = reverse(head, cur);
        head->next = reverseKGroup(cur, k);
        return new_head;
    }
private:
    ListNode* reverse(ListNode* head, ListNode* tail){
        ListNode* new_head = tail;
        while(head != tail){
            ListNode* t = head->next;
            head->next = new_head;
            new_head = head;
            head = t;
        }
        return new_head;
    }
};


2.2.10 Copy List with Random Pointer (138)
A linked list is given such that each node contains an additional random pointer which could point to
any node in the list or null.
Return a deep copy of the list.
/*这道链表的深度拷贝题的难点就在于如何处理随机指针的问题，由于每一个节点都有一个随机指针，这个指针可以为空，
也可以指向链表的任意一个节点，如果在每生成一个新节点给其随机指针赋值时，都要去遍历原链表的话，OJ 上肯定会超时，
所以可以考虑用 HashMap 来缩短查找时间，第一遍遍历生成所有新节点时同时建立一个原节点和新节点的 HashMap，第二遍给随机指针赋值时，查找时间是常数级*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*, Node*> mp;
        Node* cur = head;
        while(cur != NULL){
            mp[cur] = new Node(cur->val);
            cur = cur->next;
        }
        for(cur = head; cur != NULL; cur = cur->next){
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
        }
        return mp[head];
    }
};


2.2.11 Linked List Circle  (141)
Given a linked list, determine if it has a cycle in it.
Follow up: Can you solve it without using extra space?

class Solution{
public:
    bool hasCircle(ListNode* head){
        ListNode* slow = head, fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
}


2.2.12 Linked List Circle II  (142)
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
Follow up: Can you solve it without using extra space?
/*这里还是要设快慢指针，不过这次要记录两个指针相遇的位置，当两个指针相遇了后，让其中一个指针从链表头开始，此时再相遇的位置就是链表中环的起始位置，为啥是这样呢，因为快指针每次走2，慢指针每次走1，快指针走的距离是慢指针的两倍。而快指针又比慢指针多走了一圈。所以 head 到环的起点+环的起点到他们相遇的点的距离 与 环一圈的距离相等。现在重新开始，head 运行到环起点 和 相遇点到环起点 的距离也是相等的，相当于他们同时减掉了 环的起点到他们相遇的点的距离。*/
class Solution{
public:
    bool detectCircle(ListNode* head){
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                fast = head;
                while(fast != slow){
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast;
            }
        }
        return nullptr; 
    }
}

2.2.13 Reorder List (143)
Given a singly linked list L : L0 → L1 → · · · → Ln−1 → Ln , reorder it to: L0 → Ln → L1 →
Ln−1 → L2 → Ln−2 → · · ·
You must do this in-place without altering the nodes’ values.
For example, Given {1,2,3,4}, reorder it to {1,4,2,3}.

class Solution{
public:
    void reorderList(ListNode* head){
        if(!head || !head->next || !head->next->next) return;
        ListNode* slow = head, *fast = head;
        /*先找到list的中点*/
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        /*反转后半部分*/
        ListNode* cur = mid, pre = nullptr;
        while(cur){
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        /*把后半部分插入first part*/
        while(head && pre){
            ListNode* nxt = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = nxt;
            head = nxt;
        }
    }
}

/*解法2： 用栈来实现*/
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head || !head->next || !head->next->next) return;
        stack<ListNode*> s;
        ListNode* cur = head;
        while(cur){
            s.push(cur);
            cur = cur->next;
        }
        int cnt = ((int)s.size() - 1) / 2;
        cur = head;
        while(cnt-- > 0){
            auto tmp = s.top(); s.pop();
            ListNode* nxt = cur->next;
            cur->next = tmp;
            tmp->next = nxt;
            cur = nxt;
        }
        s.top()->next = nullptr;
    }
};


2.2.14 LRU Cache  (146)
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the
following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise
return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its
capacity, it should invalidate the least recently used item before inserting a new item.

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;    
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()) l.erase(it->second);
        l.push_front(make_pair(key, val));
        m[key] = l.begin();
        if(m.size() > cap){
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }    
    }
private:
    int cap;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


第三章 字符串

3.1 Valid Palindrome (125)
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring
cases.
For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
Note: Have you consider that the string might be empty? This is a good question to ask during an
interview.
For the purpose of this problem, we define empty string as valid palindrome.

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while(left < right){
            if(!isAlphaNum(s[left])) ++left;
            else if(!isAlphaNum(s[right])) --right;
            else if((s[left] + 32 - 'a') % 32 != (s[right] + 32 - 'a') % 32) return fase;
            else{
                ++left;
                --right;
            }
        }
        return true;    
    }
private:
    bool isAlphaNum(char &ch){
        if(ch >= 'a' && ch <= 'z') return true; 
        if(ch >= 'A' && ch <= 'Z') return true; 
        if(ch >= '0' && ch <= '9') return true;
        return false; 
    }
};


3.2 Implement strStr() (28)
Implement strStr().
Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

class Solution {
public:
    int strStr(string haystack, string needle) {
        /*brute force 解法。O(M*N)*/
        if(needle.empty()) return 0;
        const int m = haystack.size(), n = needle.size();
        if(m < n) return -1;
        for(int i = 0; i <= m - n; ++i){
            int j = 0;
            for(j = 0; j < n; ++j){
                if(haystack[i + j] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1; 
    }
};


3.3 String to Integer(atoi) (8)
Implement atoi to convert a string to an integer.
class Solution {
public:
    int myAtoi(string s) {
        int sum = 0;
        const size_t n = s.length();
        int sign = 1, i = 0;
        while(i < n && s[i] == ' ') ++i;
        if(i < n && (s[i] == '+' || s[i] == '-'))
            sign = s[i++] == '+' ? 1 : -1;
        while(i < n && s[i] >= '0' && s[i] <= '9'){
            if(sum > INT_MAX / 10 || (sum == INT_MAX / 10 && s[i] - '0' > 7))
                return sign == 1 ? INT_MAX : INT_MIN;
            sum = sum * 10 + (s[i++] - '0');
        }
        return sum * sign;
    }
};


3.4 Add Binary (67)
Given two binary strings, return their sum (also a binary string).
For example,
a = "11"
b = "1"
Return "100".

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size() - 1, n = b.size() - 1, carry = 0;
        while(m >= 0 || n >= 0){
            int p = m >= 0 ? a[m--] - '0' : 0;
            int q = n >= 0 ? b[n--] - '0' : 0;
            int sum = p + q + carry;
            res = to_string(sum % 2) + res;
            carry = sum / 2;
        }
        return carry == 1 ? "1" + res : res;
    }
};


3.5 Longest Palindromic Substring (5)
Given a string s, return the longest palindromic substring in s.

class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        if(n < 2) return s;
        int maxLen = 0, start = 0;
        for(int i = 0; i < n; ){
            if((n - i) <= maxLen / 2) break;
            int left = i, right = i;
            while(right < n - 1 && s[right] == s[right + 1]) right++;
            i = right + 1;
            while(left > 0 && right < n - 1 && s[left - 1] == s[right + 1]){
                left--; right++;
            }
            if(maxLen < right - left + 1){
                maxLen = right - left + 1;
                start = left;
            }
        }
        return s.substr(start, maxLen);        
    }
};

/*解法2: DP*/
class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.length();
        int dp[n][n];  /*dp[i][j] 表示i --j 是回文*/
        memset(dp, 0, sizeof(dp));
        int len = 1, left = 0;
        for(int i = 0; i < n; ++i){
            dp[i][i] = 1;
            for(int j = 0; j < i; ++j){
                dp[j][i] = (s[j] == s[i] && (i - j < 2 || dp[j + 1][i - 1]))
                if(dp[j][i] && len < (i - j + 1)){
                    left = j;
                    len = i - j + 1;
                }
            }
        }
        return s.substr(left, len);
    }
};


3.6 Regular Expression Matching (10)
Implement regular expression matching with support for '.' and '*'.
'.' Matches any single character. '*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
/*解题思路：
需要用递归 Recursion 来解，大概思路如下：
- 若p为空，若s也为空，返回 true，反之返回 false。
- 若p的长度为1，若s长度也为1，且相同或是p为 '.' 则返回 true，反之返回 false。
- 若p的第二个字符不为*，若此时s为空返回 false，否则判断首字符是否匹配，且从各自的第二个字符开始调用递归函数匹配。
- 若p的第二个字符为*，进行下列循环，条件是若s不为空且首字符匹配（包括 p[0] 为点），调用递归函数匹配s和去掉前两个字符的p（这样做的原因是假设此时的星号的作用是让前面的字符出现0次，验证是否匹配），若匹配返回 true，否则s去掉首字母（因为此时首字母匹配了，我们可以去掉s的首字母，而p由于星号的作用，可以有任意个首字母，所以不需要去掉），继续进行循环。
- 返回调用递归函数匹配s和去掉前两个字符的p的结果（这么做的原因是处理星号无法匹配的内容，比如 s="ab", p="a*b"，直接进入 while 循环后，我们发现 "ab" 和 "b" 不匹配，所以s变成 "b"，那么此时跳出循环后，就到最后的 return 来比较 "b" 和 "b" 了，返回 true。再举个例子，比如 s="", p="a*"，由于s为空，不会进入任何的 if 和 while，只能到最后的 return 来比较了，返回 true，正确）。*/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.empty()) return s.empty();
        if(p.size() == 1) return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));
        if(p[1] != '*'){
            if(s.empty()) return false;
            return (s[0] == p[0] || p[0] == '.') && isMatch(s.substr(1), p.substr(1)); 
        }
        while(!s.empty() && (s[0] == p[0] || p[0] == '.')){
            if(isMatch(s, p.substr(2))) return true;
            s = s.substr(1);
        }
        return isMatch(s, p.substr(2));         
    }
};

/*我们也可以用 DP 来解，定义一个二维的 DP 数组，其中 dp[i][j] 表示 s[0,i) 和 p[0,j) 是否 match，然后有下面三种情况
1.  P[i][j] = P[i - 1][j - 1], if p[j - 1] != '*' && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
2.  P[i][j] = P[i][j - 2], if p[j - 1] == '*' and the pattern repeats for 0 times;
3.  P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'), if p[j - 1] == '*' and the pattern repeats for at least 1 times.*/


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for(int i = 0; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(j > 1 && p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];        
    }
};


3.7 WildCard Matching (44)
Implement wildcard pattern matching with support for '?' and '*'.
'?' Matches any single character. '*' Matches any sequence of characters (including the empty se-
quence).
The matching should cover the entire input string (not partial).
The function prototype should be:
bool isMatch(const char *s, const char *p)
Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        int istar = -1, jstar = -1, i = 0, j = 0;
        while(i < m){
            if(j < n && s[i] == p[j]){
                ++i; ++j;
            }
            else if(j < n && p[j] == '*'){
                istar = i;
                jstar = j;
                ++j;
            }
            else if(istar >= 0){
                i = ++istar;
                j = jstar + 1;
            }
            else return false;
        }
        if(j < n && p[j] == '*') ++j;
        return j == n;
    }
};


3.8 Longest Common Prefix (14)
Write a function to find the longest common prefix string amongst an array of strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        /*纵向扫描*/
        if(str.empty()) return "";
        for(int indx = 0; indx < strs[0].size(); ++indx){
            for(int j = 1; j < strs.size(); ++j){
                if(strs[0][indx] != strs[j][indx]) return strs[0].substr(0, indx);
            }
        }
        return strs[0];
    }
};

 /*解法2：这种方法给输入字符串数组排了个序，想想这样做有什么好处？既然是按字母顺序排序的话，
那么有共同字母多的两个字符串会被排到一起，而跟大家相同的字母越少的字符串会被挤到首尾两端，
那么如果有共同前缀的话，一定会出现在首尾两端的字符串中，所以只需要找首尾字母串的共同前缀即可。
比如例子1排序后为 ["flight", "flow", "flower"]，例子2排序后为 ["cat", "dog", "racecar"]，
虽然例子2没有共同前缀，但也可以认为共同前缀是空串，且出现在首尾两端的字符串中。由于是按字母顺序排的，
而不是按长度，所以首尾字母的长度关系不知道，为了防止溢出错误，只遍历而这种较短的那个的长度，找出共同前缀返回即可，
参见代码如下：*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        int i = 0, len = min(strs[0].size(), strs.back().size());
        while(i < len && strs[0][i] == strs.back()[i]) ++i;
        return strs[0].substr(0, i);
    }
};

3.9 Valid Number (65)
Validate if a given string is numeric.
Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up
front before implementing one.
/*首先，从题目中给的一些例子可以分析出来，我们所需要关注的除了数字以外的特殊字符有空格 ‘ ’， 小数点 '.', 自然数 'e/E', 还要加上正负号 '+/-"， 除了这些字符需要考虑意外，出现了任何其他的字符，可以马上判定不是数字。下面我们来一一分析这些出现了也可能是数字的特殊字符：
1. 空格 ‘ ’： 空格分为两种情况需要考虑，一种是出现在开头和末尾的空格，一种是出现在中间的字符。出现在开头和末尾的空格不影响数字，而一旦中间出现了空格，则立马不是数字。解决方法：预处理时去掉字符的首位空格，中间再检测到空格，则判定不是数字。
2.面 小数点 '.'：小数点需要分的情况较多，首先的是小数点只能出现一次，但是小数点可以出现在任何位置，开头(".3"), 中间("1.e2"), 以及结尾("1." ), 而且需要注意的是，小数点不能出现在自然数 'e/E' 之后，如 "1e.1" false, "1e1.1" false。还有，当小数点位于末尾时，前必须是数字，如 "1."  true，" -." false。解决方法：开头中间结尾三个位置分开讨论情况。
3. 自然数 'e/E'：自然数的前后必须有数字，即自然数不能出现在开头和结尾，如 "e" false,  ".e1" false, "3.e" false, "3.e1" true。而且小数点只能出现在自然数之前，还有就是自然数前面不能是符号，如 "+e1" false, "1+e" false. 解决方法：开头中间结尾三个位置分开讨论情况。
4. 正负号 '+/-"，正负号可以再开头出现，可以再自然数e之后出现，但不能是最后一个字符，后面得有数字，如  "+1.e+5" true。解决方法：开头中间结尾三个位置分开讨论情况。*/

/*下面我们开始正式分开头中间结尾三个位置来讨论情况：
1. 在讨论三个位置之前做预处理，去掉字符串首尾的空格，可以采用两个指针分别指向开头和结尾，遇到空格则跳过，分别指向开头结尾非空格的字符。
2. 对首字符处理，首字符只能为数字或者正负号 '+/-"，我们需要定义三个flag在标示我们是否之前检测到过小数点，自然数和正负号。首字符如为数字或正负号，则标记对应的flag，若不是，直接返回false。
3. 对中间字符的处理，中间字符会出现五种情况，数字，小数点，自然数，正负号和其他字符。
若是数字，标记flag并通过。
若是自然数，则必须是第一次出现自然数，并且前一个字符不能是正负号，而且之前一定要出现过数字，才能标记flag通过。
若是正负号，则之前的字符必须是自然数e，才能标记flag通过。
若是小数点，则必须是第一次出现小数点并且自然数没有出现过，才能标记flag通过。
若是其他，返回false。
4. 对尾字符处理，最后一个字符只能是数字或小数点，其他字符都返回false。
若是数字，返回true。
若是小数点，则必须是第一次出现小数点并且自然数没有出现过，还有前面必须是数字，才能返回true。*/

class Solution {
public:
    bool isNumber(string s) {
        const int n = s.size();
        int i = 0, j = n - 1;
        bool eExisted = false;
        bool dotExisted = false;
        bool digitExisted = false;
        /*delete space of head and tail*/
        while(s[i] == ' ') ++i;
        while(s[j] == ' ') --j;
        /*if only have one char and not digit, return false*/
        if(i >= j && (s[i] < '0' s[i] > '9')) return false;
        /*process the first char*/
        if(s[i] == '.') dotExisted = true;
        else if(s[i] >= '0' && s[i] <= '9') digitExisted = true;
        else if(s[i] != '+' || s[i] != '-') return false;
        /*处理中间的字符*/
        for(int cur = i + 1; cur < j - 1; ++cur){
            if(s[cur] >= '0' && s[cur] <= '9') digitExisted = true;
            else if(s[cur] == 'e' || s[cur] == 'E'){
                if(!eExisted && s[cur - 1] != '+' && s[cur - 1] != '-' && digitExisted) eExisted = true;
                else return false;
            }
            else if(s[cur] == '+' || s[cur] == '-'){
                if(s[cur - 1] != 'e' && s[cur - 1] != 'E') return false;
            }
            else if(s[cur] == '.'){
                if(!dotExisted && !eExisted) dotExisted = true;
            }
            else
                return false;
        }
        if(s[j] >= '0' && s[j] <= '9') return true;
        else if(s[j] == '.' && !dotExisted && !eExisted && digitExisted) return true;
        else return false;
    }
};

 /*本题的主框架是找到科学记数法的标记“e”。“e”之前和之后的两个子字符串必须分别都是合法的“数”。但是“e”之前的子字符串允许是一个小数，后者只允许是整数。合法的小数的定义是：数字+最多一个小数点。合法的整数的定义是：数字+没有小数点。
任何正负号，只可能出现在合法的数（无论整数或小数）的第一个字符的位置。
可能需要单独判断的corner cases是：只有小数点或空或“e”的字符串都不是合法的数。*/
class Solution {
public:
    bool isNumber(string s) {
        while(s.size() > 0 && s.back() == ' ') s.pop_back();
        while(s.size() > 0 && s[0] == ' ') s.erase(s.begin());
        if(s == "") return false;
        int cntE = 0, posE = -1;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == 'e' || s[i] == 'E'){
                ++cntE;
                posE = i;
            }
        }
        if(cntE > 1) return false;
        if(cnt == 0) return isOk(s, 1);

        return isOk(s.substr(0, posE), 1) && isOk(s.substr(posE + 1), 0);   
    }

    bool isOk(string s, int k){
        for(int i = 0; i < s.size(); ++i)
            if((s[i] == '+' || s[i] == '-') && i != 0)
                return false;
        if(s[0] == '+' || s[0] == '-')
            s.erase(s.begin());
        if(s == "" || s == ".") return false;
        
        int cntDot = 0;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '.') cntDot++;
            else if(!isdigit(s[i])) return false;
        }

        return cntDot <= k;
    }
};


3.10 Integer to Roman
Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < val.size(); ++i){
            while(num >= val[i]){
                num -= val[i];
                res += str[i];
            }
        }
        return res;
    }
};

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int> val{1000, 500, 100, 50, 10, 5, 1};
        vector<char> roma{'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        for(int n = 0; n < val.size(); n += 2){
566            int x = num / val[n];
            if(x < 4){
                for(int i = 1; i <= x; ++i) res += roma[n];
            }
            else if(x == 4) res = res + roma[n] + roma[n - 1];
            else if(x > 4 && x < 9){
                res = res + roma[n - 1];
                for(int i = 6; i <= x; ++i) res += roma[n];
            }
            else if(x == 9)
                res = res + roma[n] + roma[n - 2];
            num = num % val[n];
        }
        return res;
    }
};


3.11 Roman to Integer
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<char, int> m{{'I', 1}, {'V',5}, {'X',10}, {'L', 50}, {'C', 100}, {'D', 500},{'M', 1000}};
        for(int i = 0; i < s.size(); ++i){
            int tmp = m[s[i]];
            if(i == s.size() - 1 || tmp >= m[s[i + 1]]) res += tmp;
            else res -= tmp;
        }
        return res;
    }
};


3.12 Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2", then "one 1" or 1211.
Given an integer n, generate the nth sequence.
Note: The sequence of integers will be represented as a string.

/*这道计数和读法问题还是第一次遇到，看似挺复杂，其实仔细一看，算法很简单，就是对于前一个数，找出相同元素的个数，把个数和该元素存到新的 string 里.*/
class Solution {
public:
    string countAndSay(int n) {
        if(n <= 0) return "";
        string res = "1";
        while(--n){
            string cur = "";
            for(int i = 0; i < res.size(); ++i){
                int cnt = 1;
                while(i + 1 < res.size() && res[i] == res[i + 1]){
                    ++cnt; ++i;
                }
                cur += to_string(cnt) + res[i]
            }
            res = cur;
        }
        return res;
    }
};


3.13 Group Anagrams (49)
Given an array of strings, group anagrams together.
Example:
Input: 
["eat", "tea", "tan", "ate", "nat", "bat"]
,
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
/*由于错位词重新排序后都会得到相同的字符串，以此作为 key，将所有错位词都保存到字符串数组中，建立 key 和当前的不同的错位词集合个数之间的映射，这里之所以没有建立 key 和其隶属的错位词集合之间的映射，是用了一个小 trick，从而避免了最后再将 HashMap 中的集合拷贝到结果 res 中。当检测到当前的单词不在 HashMap 中，此时知道这个单词将属于一个新的错位词集合，所以将其映射为当前的错位词集合的个数，然后在 res 中新增一个空集合，这样就可以通过其映射值，直接找到新的错位词集合的位置，从而将新的单词存入结果 res 中*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        for(string str : strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(!m.count(tmp)){
                m[tmp] = res.size();
                res.push_back({});
            }
            res[m[tmp]].push_back(str);
        }
        return res;   
    }
};

/*下面这种解法没有用到排序，用一个大小为 26 的 int 数组来统计每个单词中字符出现的次数，然后将 int 数组转为一个唯一的字符串，跟字符串数组进行映射，这样就不用给字符串排序了*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<stirng, vector<string>> m;
        for(string str : strs){
            vector<int> cnt(26);
            string t;
            for(char c : str) ++cnt[c - 'a'];
            for(int i = 0; i < 26; ++i){
                if(cnt[i] == 0) continue;
                t += string(1, i + 'a') + to_string(cnt[i]);
            }
            m[t].push_back(str);
        }
        for(auto it : m){
            res.push_back(it.second);
        }
        returen res;    
    }
};

LeetCode 438 Relate Problem

3.14 Simplfy Path (71)
Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
Corner Cases:
• Did you consider the case where path = "/../"? In this case, you should return "/".
• Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> strs;
        int i = 0, n = path.size();
        while(i < n){
            while(path[i] == '/' && i < n) ++i;
            if(i == n) break;
            int start = i;
            while(path[i] != '/' && i < n) ++i;
            int end = i - 1;
            string tmp = path.substr(start, end - start + 1));
            if(tmp == ".."){
                if(!strs.empty()) strs.pop_back();
            }
            else if(tmp != ".") strs.push_back(tmp);
        }
        if(strs.empty()) return "/";
        string res;
        for(string str : strs)
            res += "/" + str;
        
        return res;
    }
};

3.15 Length of Last Word (58)
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length
of last word in the string.
If the last word does not exist, return 0.
Note: A word is defined as a character sequence consists of non-space characters only.
For example, Given s = "Hello World", return 5.

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int right = s.size() - 1;
        while(right >= 0 && s[right] == ' ') --right;
        while(right >= 0 && s[right] != ' '){
            --right; ++res;
        }
        return res;
    }
};


第四章 栈和队列
4.1 栈
4.1.1 Valid Parentheses
20. Valid Parentheses
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            else if(!st.empty() && st.top() == c) st.pop();
            else return fase;
        }
        return st.empty();    
    }
};


4.1.2 Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-
formed) parentheses substring.
For "(()", the longest valid parentheses substring is "()", which has length = 2.
Another example is ")()())", where the longest valid parentheses substring is "()()", which has
length = 4

class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, n = s.size(), start = 0;
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(s[i] == '(') st.push(i);
            else{
                if(st.empty()) start = i + 1;
                else{
                    st.pop();
                    res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
                }
            }
        }
        return res;
    }
};

/*两遍扫描*/
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0, left = 0, right = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            s[i] == '(' ? ++left : ++right;
            if(left == right) res = max(res, 2*right);
            else if(right > left) left = right = 0;
        }
        left = right = 0;
        for(int i = n - 1; i >= 0; --i){
            s[i] == '(' ？ ++left : ++right;
            if(left == right) res = max(res, 2 * left);
            else if(left > right) left = right = 0;
        }
        return res;
    }
};


4.1.3 Largest Rectangle in Histogram (84)
Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
/*遍历数组，每找到一个局部峰值（只要当前的数字大于后面的一个数字，那么当前数字就看作一个局部峰值，跟前面的数字大小无关），然后向前遍历所有的值，算出共同的矩形面积，每次对比保留最大值。这里再说下为啥要从局部峰值处理，看题目中的例子，局部峰值为 2，6，3，我们只需在这些局部峰值出进行处理，为啥不用在非局部峰值处统计呢，这是因为非局部峰值处的情况，后面的局部峰值都可以包括，比如1和5，由于局部峰值6是高于1和5的，所有1和5能组成的矩形，到6这里都能组成，并且还可以加上6本身的一部分组成更大的矩形，那么就不用费力气去再统计一个1和5处能组成的矩形了。*/

/*超时解法*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        for(int i = 0; i < heights.size(); ++i){
            if(i + 1 < heights.size() && heights[i] <= heights[i + 1]) continue;
            int minH = heights[i];
            for(int j = i; j >= 0; --j){
                minH = min(minH, heights[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;        
    }
};

/*单调栈解法*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> st;
        heights.push_back(0);
        for(int i = 0; i < heights.size(); ++i){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int cur = st.top(); st.pop();
                res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;            
    }
};


4.1.4 Evaluate Reverse Polish Notation (150)
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
Valid operators are +, -, *, /. Each operand may be an integer or another expression.
Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(int i = 0; i < n; ++i){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
                st.push(stoi(tokens[i]));
            else{
                int num1 = st.top(); st.pop();
                int num2 = st.top(); st.pop();
                if(tokens[i] == "+") st.push(num2 + num1);
                if(tokens[i] == "-") st.push(num2 - num1);
                if(tokens[i] == "*") st.push(num2 * num1);
                if(tokens[i] == "/") st.push(num2 / num1);
            }
        }
        return st.top();
    }
};


4.2 队列

第五章 树
Leetcode 树的节点定义如下。
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr){}
};

5.1 二叉树的遍历
DFS and BFS
DFS 又分为 先序，中序，后序

5.1.1 Binary Tree Preorder Traversal (144)
/*Recursive Solution*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
private:
    void helper(TreeNode*root, vector<int>& res){
        if(root == NULL) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};
/*Iterative Solution*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<int> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* cur = st.top(); st.pop();
            res.push_back(cur->val);
            if(cur->right) st.push(cur->right);
            if(cur->left) st.push(cur->left);
        }
        return res;
    }
};

/*Iterative Solution 2*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<int> st;
        TreeNode* cur = root
        while(!st.empty() || cur){
            if(cur){
                res.push_back(cur->val);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                cur = cur->right;
            }
        }
        return res;
    }
};

/*Morris Traversal*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur = root, pre;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right != cur) pre = pre->right;
                if(pre->right == NULL){
                    pre->right = cur;
                    res.push_back(cur->val);
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }
}

5.1.2 Binary Tree Inorder Traversal (94)
Given a binary tree, return the inorder traversal of its nodes’ values.
For example: Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].
Note: Recursive solution is trivial, could you do it iteratively?
/*Recursive Solution*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        /*if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        while(!st.empty)() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;*/

        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while(!st.empty() || cur){
            if(cur){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top(); st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};

/*Recursive Solution*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        inorder(root, res);
        return res;    
    }
private:
    void inOrder(TreeNode* root, vector<int>& res){
        if(!root) return;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
}

/*Morris Traversal 线索二叉树*/
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        TreeNode* cur = root, *pre;
        while(cur){
            if(!cur->left){
                res.push_back(cur->val);
                cur = cur->right;
            }
            else{
                pre = cur->left;
                while(pre->right && pre->right != cur) pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                }
                else{
                    pre->right = NULL;
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return res;
    }
}

5.1.3 Binary Tree Postorder Traversal  (145)
Given a binary tree, return the postorder traversal of its nodes’ values.
For example: Given binary tree {1,#,2,3},
1
\
2
/
3
return [3,2,1].
Note: Recursive solution is trivial, could you do it iteratively?
/*Iterative Solution*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        stack<TreeNode*> st{{root}};
        while(!st.empty()){
            TreeNode* cur = st.top(); st.pop();
            res.insert(res.begin(), cur->val);
            if(cur->left) st.push(cur->left);
            if(cur->right) st.push(cur->right);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> res;
        postOrder(root, res);
        return res;
    }
private:
    void postOrder(TreeNode* root, vector<int>& res){
        if(!root) return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
};


5.1.4 Binary Tree Level Order Traversal  (102)
Given a binary tree, return the level order traversal of its nodes’ values. (ie, from left to right, level by
level).
For example: Given binary tree {3,9,20,#,#,15,7},
3
/ \
9 20
/ \
15
 7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; ++i){
                TreeNode* t = q.front(); q.pop();
                tmp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;    
    }
};

/*Recursive Solution*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return res;    
    }
private:
    void levelorder(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        if(res.size() == level) res.push_back({});
        res[level].push_back(root->val);
        levelorder(root->left, level + 1, res);
        levelorder(root->right, level + 1, res);
    }
};


5.1.5 Binary Tree Level Order Traversal II
Given a binary tree, return the bottom-up level order traversal of its nodes’ values. (ie, from left to right,
level by level from leaf to root).
For example: Given binary tree {3,9,20,#,#,15,7},
3
/ \
9 20
/ \
15
 7
return its bottom-up level order traversal as:
[
]
[15,7]
[9,20],
[3],

/*Queue Solution*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = size();
            vector<int> tmp;
            for(int i = 0; i < n; ++i){
                TreeNode* t = q.front(); q.pop();
                tmp.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.insert(res.begin(), tmp);
        }
        return res;    
    }
}

/*Recursive Solution*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        leevelorderbottom(root, 0, res);
        return vector<vector<int>>(res.rbegin(), res.rend());        
    }
private:
    void levelorderbottom(TreeNode* root, int level, vector<vector<int>>& res){
        if(!root) return;
        if(level == res.size()) res.push_back({});
        res[level].push_back(root->val);
        levelorderbottom(root->left, level + 1, res);
        levelorderbottom(root->right, level + 1, res);
    }
}


5.1.6 Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right,
then right to left for the next level and alternate between).
For example: Given binary tree 3,9,20,#,#,15,7,
3
/ \
9 20
/ \
15
 7
return its zigzag level order traversal as:
[
]
[3],
[20,9],
[15,7]
/*Queue Solution*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> tmp;
            for(int i = 0; i < n; ++i){
                TreeNode* t = q.front(); q.pop();
                if(level % 2 == 0) tmp.push_back(t->val);
                else tmp.insert(tmp.begin(), t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ++level;
            res.push_back(tmp);
        }
        return res;    
    }
};

/*Recursive Solution*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        zigzaglevelorder(root, 0, res);
        return res;    
    }
private:
    void zigzaglevelorder(TreeNode* root, int level, vector<vcetor<int>>& res){
        if(!root) return;
        if(level == res.size()) res.push_back({});
        if(level % 2 == 0) res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        zigzaglevelorder(root->left, level + 1, res);
        zigzaglevelorder(root->right, level + 1, res);
    }
};

5.1.7 Recover Binary Search Tree (99)
Two elements of a binary search tree (BST) are swapped by mistake.
Recover the tree without changing its structure.
Note: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
private:
    TreeNode* pre = new TreeNode(INT_MIN);
    TreeNode* first = nullptr, *second = nullptr;
    void inorder(TreeNode* root){
        if(!root) return;
        stack<int> s;
        while(!st.empty() || root){
            while(root){
                st.push(root);
                root = root->left;
            }
            root = st.top(); st.pop();
            if(first == nullptr && root->val < pre->val) first = pre;
            if(first != nullptr && root->val < pre->val) second = root;
            pre = root;
            root = root->right;
        }
    }
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        in-order(root);
        swap(first->val, second->val);
    }
private:
    void in-order(TreeNode* root){
        if(!root) return;
        in-order(root->left);
        if(first == nullptr && root->val < pre->val) first = pre;
        if(first != nullptr && root->val < pre->val) second = root;
        pre = root;
        in-order(root->right);
    }
};

5.1.8 Same Tree (100)
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
/*Recursive Solution*/
class Solution {class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!q && !p) return true;
        else if(!q || !p || p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

/*Iterative Solution--preorder*/
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> s;
        s.push(p); s.push(q);
        while(!s.empty()){
            q = s.top(); s.pop();
            p = s.top(); s.pop()
            if(!q && !p) continue;
            else if(p->val != q->val || !q || !p) return false;
            s.push(p->right); s.push(q->right);
            s.push(p->left); s.push(q->left);
        }
        return true;    
    }
};

/*Iterative Solution -- level-order*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> que;
        que.push(p); que.push(q);
        while(!que.empty()){
            p = que.front(); que.pop();
            q = que.front(); que.pop();
            if(!q && !p) continue;
            if(!q || !p || q->val != p->val) return false;
            que.push(p->left); que.push(q->left);
            que.push(p->right); que.push(q->right);
        }
        return true;        
    }
};

5.1.19 Symmetric Tree
Given two binary trees, write a function to check if they are equal or not.
Two binary trees are considered equal if they are structurally identical and the nodes have the same value.

/*Recursive Solution*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(!q || !p || p->val != q->val) return false;
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};

/*Iterative Solution*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        stack<TreeNode*> s;
        s.push(root->left); s.push(root->right);
        while(!s.empty()){
            TreeNode* p = s.top(); s.pop();
            TreeNode* q = s.top(); s.pop();
            if(!q && !p) continue;
            if(!q || !p || p->val != q->val) return false;
            s.push(p->right); s.push(q->left);
            s.push(p->left); s.push(q->right);
        }
        return true;
    }
};

5.1.10 Balanced Binary Tree
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two
subtrees of every node never differ by more than 1.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        if(abs(getdeepth(root->left) - getdeepth(right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(right);      
    }
private:
    int getdeepth(TreeNode* root){
        if(!root) return 0;
        return max(getdeepth(root->left), getdeepth(root->right)) + 1;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return balanceHeight(root) >= 0    
    }
private:
    int balanceHeight(TreeNode* root){
        if(!root) return 0; /*结束条件*/
        int left = balanceHeight(root->left);
        int right = balanceHeight(root->right);
        if(left < 0 || right < 0 || abs(left - right) > 1) return -1;
        return 1 + max(left, max);
    }

};

5.1.11Flatten Binary Tree to Linked List
Given a binary tree, flatten it to a linked list in-place.
/*Iterative Solution*/
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur){
            if(cur->left){
                TreeNode* p = cur->left;
                while(p->right) p = p->right;
                p->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

/*Recursive(DFS) solution*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        TreeNode* tmp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right) root = root->right;
        root->right = tmp;
    }
};

/*Iterative Solution 2*/
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* t = s.top(); s.pop();
            if(t->right) s.push(t->right);
            if(t->left) s.push(t->left);
            t->left = NULL;
            if(!s.empty()) t->right = s.top();
        }
    }
};

5.1.12Populating Next Right Pointers in Each Node II (116, 117)

Follow up for problem ”Populating Next Right Pointers in Each Node”.
What if the given tree could be any binary tree? Would your previous solution still work?
Note: You may only use constant extra space.
For example, Given the following binary tree,
1
/ \
2 3
/ \ \
4 5 7
After calling your function, the tree should look like:
1 -> NULL
/ \
2 -> 3 -> NULL
/ \ \
4-> 5 -> 7 -> NULL

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*116 Recursive solution*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;    
    }
};
/*116 Iterative Solution*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* start = root, *cur = NULL;
        while(start->left){
            cur = start;
            while(cur){
                cur->left->next = cur->right;
                cur->right->next = cur->next ? cur->next->left : NULL;
                cur = cur->next;
            }
            start = start->left;
        }    
    }
};

/*117 Recursive Solution*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* p = root->next;
        while(p){
            if(p->left){
                p = p->left; break;
            }
            if(p->right){
                p = p->right; break;
            }
            p = p->next;
        }
        if(root->right) root->right->next = p;
        if(root->left) root->left->next = root->right ? root->right : p;
        connect(root->left);
        connect(root->right);
        return root;   
    }
};

/*，我们建立一个 dummy 结点来指向每层的首结点的前一个结点，然后指针 cur 用来遍历这一层，这里实际上是遍历一层，然后连下一层的 next，首先从根结点开始，如果左子结点存在，那么 cur 的 next 连上左子结点，然后 cur 指向其 next 指针；如果 root 的右子结点存在，那么 cur 的 next 连上右子结点，然后 cur 指向其 next 指针。此时 root 的左右子结点都连上了，此时 root 向右平移一位，指向其 next 指针，如果此时 root 不存在了，说明当前层已经遍历完了，重置 cur 为 dummy 结点，root 此时为 dummy->next，即下一层的首结点，然后 dummy 的 next 指针清空，或者也可以将 cur 的 next 指针清空，因为前面已经将 cur 赋值为 dummy 了。那么现在想一想，为什么要清空？因为用 dummy 的目的就是要指到下一行的首结点的位置即 dummy->next，而一旦将 root 赋值为 dummy->next 了之后，这个 dummy 的使命就已经完成了，必须要断开，如果不断开的话，那么假设现在 root 是叶结点了，那么 while 循环还会执行，不会进入前两个 if，然后 root 右移赋空之后，会进入最后一个 if，之前没有断开 dummy->next 的话，那么 root 又指向之前的叶结点了，死循环诞生了，跪了。所以一定要记得清空哦，呵呵哒～

这里再来说下 dummy 结点是怎样指向每层的首结点的前一个结点的，过程是这样的，dummy 是创建出来的一个新的结点，其目的是为了指向 root 结点的下一层的首结点的前一个，具体是这么做到的呢，主要是靠 cur 指针，首先 cur 指向 dummy，然后 cur 再连上 root 下一层的首结点，这样 dummy 也就连上了。然后当 root 层遍历完了之后，root 需要往下移动一层，这样 dummy 结点之后连接的位置就正好赋值给 root，然后 cur 再指向 dummy，dummy 之后断开，这样又回到了初始状态，以此往复就可以都连上了，*/
/*117 Iterative*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        Node* Dummy = new Node(-1), *cur = Dummy, *head = root;
        while(root){
            if(root->left){
                cur->next = root->left;
                cur = cur->next;
            }
            if(root->right){
                cur->next = root->right;
                cur = cur->next;
            }
            root = root->next;
            if(!root){
                cur = Dummy;
                root = Dummy->next;
                Dummy->next = NULL;
            }
        }
        return head;
    }
};


5.2 二叉树的构建
5.2.1 Construct Binary Tree from Preorder and Inorder Traversal (105)

/*Recursive(DFS) Solution*/
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size(), preorderIndex = 0;
        for(int i = 0; i < n; ++i) mp[inorder[i]] = i;
        return help(inorder, 0, n - 1; preorder, preorderIndex);          
    }
private:
    unordered_map<int> mp;
    TreeNode* help(vector<int>& inorder, int inorderStart, int inorderEnd, vector<int>& preorder, int& preorderIndex){
        if(inorderStart > inorderEnd) return nullptr;
        int rootVal = preorder[preorderIndex++];
        int index = mp[rootVall];
        TreeNode* root = new TreeNode(rootVal);
        root->left = help(inorder, inorderStart, index - 1, preorder, preorderIndex);
        root->right = help(inorder, index + 1, inorderEnd, preorder, preorderIndex);
        return root;
    }
};

5.2.2 Construct Binary Tree from Inorder and Postorder Traversal
Given inorder and postorder traversal of a tree, construct the binary tree.
Note: You may assume that duplicates do not exist in the tree.

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size(), pIndex = n - 1;
        for(int i = 0; i < n; ++i)  mp[inorder[i]] = i;
        return help(inorder, 0, n - 1, postorder, pIndex);       
    }
private:
    unordered_map<int, int> mp;
    TreeNode* help(vector<int>& inorder, int inStart, int inEnd, vector<int> postorder, int& pIndex){
        if(inStart > inEnd || pIndex < 0) return nullptr;
        int rootVal = postorder[pIndex--];
        int index = mp[rootVal];
        TreeNode* root = new TreeNode(rootVal);
        root->right = help(inorder, index + 1, inEnd, postorder, pIndex);
        root->left = help(inorder, inStart, index - 1, postorder, pIndex);
        return root;
    }
};

5.3 二叉查找树
5.3.1 Unique Binary Search Trees (96)
Given n, how many structurally unique BST’s (binary search trees) that store values 1...n?
For example, Given n = 3, there are a total of 5 unique BST’s.

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];       
    }
};


5.3.2 Unique Binary Search Trees II  (95)
Given n, generate all structurally unique BST’s (binary search trees) that store values 1...n.
For example, Given n = 3, your program should return all 5 unique BST’s shown below.
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return helper(1, n);
    }
private:
    vector<TreeNode*> helper(int start, int end){
        if(start > end) return {nullptr};
        vector<TreeNode*> res;
        for(int i = start; i <= end; ++i){
            auto left = helper(start, i - 1), right = helper(i + 1, end);
            for(auto l : left){
                for(auto r : right){
                    TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
        }
        return res;
    }
};


5.3.3 Validate Binary Search Tree
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
• The left subtree of a node contains only nodes with keys less than the node’s key.
• The right subtree of a node contains only nodes with keys greater than the node’s key.
• Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);   
    }
private:
    bool isValidBST(TreeNode* root, int lower, int upper){
        if(!root) return true;
        return root->val > lower && root->val < upper && isValidBST(root->left, lower, root->val) && isValidBST(root->right, root->val, upper);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* pre = nullptr;
        return isValidBST(root, pre);
    }
private:
    bool inorder(TreeNode* node, TreeNode* & pre){
        if(!node) return true;
        bool res = isValidBST(root->left, pre);
        if(!res) return false;
        if(pre && root->val <= pre->val) return false;
        pre = root;
        return inorder(node->right, pre);
    }
};


5.3.4 Convert Sorted Array to Binary Search Tree (108)
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);  
    }
private:
    TreeNode* helper(vector<int>& nums, int left, int right){
        if(left < right) return nullptr;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        int mid = nums.size() / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        vector<int> left(nums.begin(), nums.begin() + mid), right(nums.begin() + mid + 1, numd.end());
        cur->left = sortedArrayToBST(left); 
        cur->right = sortedArrayToBST(right);
        return cur; 
    }
};


5.3.5 Convert Sorted List to Binary Search Tree (109)
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced
BST.
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        /*快慢指针*/
        if(!head) return nullptr;
        if(!head->next) return new TreeNode(head->val);
        ListNode* fast = head, *slow = head, pre = slow;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        pre->next = nullptr;
        TreeNode* root = new TreeNode(slow->val);
        if(slow != head) root->left = sortedListToBST(head);
        root->right = sortedListToBST(fast);
        return root;
    }
private:
    int listLength(ListNode* node){
        int len = 0;
        while(node){
            ++len;
            node = node->next;
        }
        return len;
    }

    ListNode* nth_node(ListNode* node, int n){
        while(--n)
            node = node->next;
        return node;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        return helper(head, NULL);        
    }
private:
    TreeNode* helper(ListNode* head, ListNode* tail){
        if(head == tail) return NULL;
        ListNode* fast = head, *slow = head;
        while(fast != tail && fast->next != tail){
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        fast = slow->next;
        root->left = helper(head, slow);
        root->right = helper(fast, tial);
        return root;
    }
};


5.4 二叉树的递归
5.4.1 Minimum Depth of Binary Tree
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest
leaf node.

/*DFS solution*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));    
    }
};

/*BFS solution*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int deepth = 0;
        while(!q.empty()){
            ++deepth;
            int n = s.size();
            for(int i = 0; i < n; ++i){
                TreeNode* t = q.top(); q.pop();
                if(!t->left && !t->right) return deepth;
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return -1;    
    }
};

5.4.2 Maximum Depth of Binary Tree (104)
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the
farthest leaf node.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        retur max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res = 0;
        while(!q.empty()){
            ++res;
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode* t = q.front(); q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return res;        
    }
};


5.4.3 Path Sum (112)
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the
values along the path equals the given sum.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        if(!root->left && !root->right) return root->val == targetSum;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        stack<TreeNode*> s({root});
        while(!s.empty()){
            TreeNode* t = s.top(); s.pop();
            if(!t->left && !t->right){
                if(t->val == targetSum)
                    return true;
            }
            if(t->right){
                t->right->val += t->val;
                s.push(t->right);
            }
            if(t->left){
                t->left->val += t->left;
                s.push(t->left);
            }
        }
        return false;
    }
};


5.4.4Path Sum II (113)
Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.
For example: Given the below binary tree and sum = 22,

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(root, targetSum, res, tmp);
        return res;
    }
private:
    void dfs(TreeNode* root, int targetSum, vector<vector<int>>& res, vector<int>& tmp){
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val == targetSum)
            res.push_back(tmp);
        dfs(root->left, targetSum - root->val, res, tmp);
        dfs(root->right, targetSum - root->val, res, tmp);
        tmp.pop_back();
    }
};

5.4.5 Binary Tree Maximum Path Sum (124)
Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree. For example: Given the below binary tree,

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;    
    }
private:
    int helper(TreeNode* root, int& res){
        if(!root) return 0;
        int left = max(helper(root->left, res), 0);
        int right = max(helper(root->right, res), 0);
        res = max(res, left + right + root->val);
        return max(left, right) + root->val;   
    }
};

5.4.6 Populating Next Right Pointers in Each Node
Given a binary tree
struct TreeLinkNode {
int val;
TreeLinkNode *left, *right, *next;
TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer
should be set to NULL.
Initially, all next pointers are set to NULL.
Note:
• You may only use constant extra space.
• You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent
has two children).
For example, Given the following perfect binary tree,

class Solution {
public:
    Node* connect(Node* root) {
        /*Recursive Solution*/
        /*if(!root) return NULL;
        if(root->left) root->left->next = root->right;
        if(root->right) root->right->next = root->next ? root->next->left : NULL;
        connect(root->left);
        connect(root->right);
        return root;*/
        if(!root) return NULL;
        Node* start = root, *cur = NULL;
        while(start->left) {
            cur = start;
            while(cur){
                cur->left->next = cur->right;
                if(cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }
            start = start->left;
        }
        return root;
    }
};

5.4.7 Sum Root to Leaf Numbers
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
An example is the root-to-leaf path 1->2->3 which represents the number 123.
Find the total sum of all root-to-leaf numbers.
For example,
1
/ \
2
 3
13.
The root-to-leaf path 1->2 represents the number 12. The root-to-leaf path 1->3 represents the number
Return the sum = 12 + 13 = 25.

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
private:
    int dfs(TreeNode* root, int sum){
        if(!root) return 0;
        if(!root->left && !root->right) return 10 * sum + root->val;
        return dfs(root->left, 10 * sum + root->val) + dfs(root->right, 10 * sum + root->val); 
    }
};

第六章 排序
6.1 Merge Sorted Array (88)
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note: You may assume that A has enough space to hold additional elements from B. The number of
elements initialized in A and B are m and n respectively.

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while(i >= 0 &&  j >= 0){
            nums1[k--] = nums1[i] > nums2[j] ? nums[i--] : nums[j--];
        }
        while(j >= 0) nums1[k--] = nums2[j--];
    }
};

6.2 Merge Two Sorted Lists (21)
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together
the nodes of the first two lists.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* Dummy = new ListNode(-1);
        ListNode* cur = Dummy;
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != NULL ? l1 : l2;
    }
};

/*Recursive Solution*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

6.3 Merge k Sorted Lists (23)
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size();
        partion(lists, 0, n - 1);
    }
private:
    ListNode* partion(ListNode* lists, int start, int end){
        if(start == end) return lists[start];
        while(start < end){
            int mid = start + (end - start) / 2;
            ListNode* l = partion(lists, start, mid);
            ListNode* r = partion(lists, mid + 1, end);
            return mergeTwoLists(l, r);
        }
        return NULL;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode* Dummy = new ListNode(-1);
        ListNode* cur = Dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != NULL ? l1 : l2;
        return Dymmy->next;
    }
};

/*Solution Two: use Priority Queue, 最小堆*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [] (ListNode* & a, ListNode* & b){
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        for(auto node : lists)
            if(node) q.push(node);
        ListNode* Dummy = new ListNode(-1), *cur = Dummy;
        while(!q.empty()){
            auto t = q.top(); q.pop();
            cur->next = t;
            cur = cur->next;
            if(cur->next) q.push(cur->next);
        }
        return Dummy->next;            
    }
};

6.4 Insertion Sort List (147)
Sort a linked list using insertion sort.

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(-1), *cur = dummy;
        while(head){
            ListNode* t = head->next;
            cur = dummy;
            while(cur->next && cur->next->val <= head->val)
                cur = cur->next;
            head->next = cur->next;
            cur->next = head;
            head = t;
        }
        return dummy->next;
    }
};

6.5 Sort List  (148)
Sort a linked list in O(nlogn) time using constant space complexity.

/*Solution 1: Merge Sort: divid and conquer*/
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = head, *slow = head, *pre = head;
        while(fast && fast->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        return merge(sortList(head), sortList(slow));
    }

    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(-1), cur = dummy;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 != NULL ? l1 : l2;
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* dummy = new ListNode(-1), *cur = head;
        dummy->next = head;
        struct cmp{
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
        };
        /*auto cmp = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };*/
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        while(cur){
            pq.push(cur);
            cur = cur->next;
        }
        cur = dummy;
        while(!pq.empty()){
            cur->next = pq.top();
            pq.pop();
            cur = cur->next;
        }
        cur->next = NULL;
        return dummy->next;
    }
};

6.6 First Missing Positive  (41)
Given an unsorted integer array, find the first missing positive integer.
For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.
Your algorithm should run in O(n) time and uses constant space.

/*使用hashset，但不是O(1)的空间复杂度*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1, n = nums.size();
        while(res <= n){
            if(!s.count(res)) return res;
            ++res;
        }
        return res;    
    }
};
/*思路是把1放在数组第一个位置 nums[0]，2放在第二个位置 nums[1]，即需要把 nums[i] 放在 nums[nums[i] - 1]上，遍历整个数组，如果 nums[i] != i + 1, 而 nums[i] 为整数且不大于n，另外 nums[i] 不等于 nums[nums[i] - 1] 的话，将两者位置调换，如果不满足上述条件直接跳过，最后再遍历一遍数组，如果对应位置上的数不正确则返回正确的数*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};


6.7 Sort Colors (75)
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are
adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library’s sort function for this problem.
Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0’s, 1’s, and 2’s, then overwrite array with total number of 0’s,
then 1’s and followed by 2’s.
Could you come up with an one-pass algorithm using only constant space?

/*这道题的本质还是一道排序的题，题目中给出提示说可以用计数排序，需要遍历数组两遍，那么先来看这种方法。
- 首先遍历一遍原数组，分别记录 0，1，2 的个数。
- 然后更新原数组，按个数分别赋上 0，1，2。*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color(3);
        for(int num : nums) ++color[num];
        int cur = 0;
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < color[i]; ++j){
                nums[cur++] = i; 
            }
        }
    }
};

/*双指针解法*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = nums.size() -1, cur = 0;
        while(cur <= r){
            if(nums[cur] == 0) swap(nums[cur++], nums[l++]);
            else if(nums[cur] == 2) swap(nums[cur], nums[r--]);
            else ++cur;
        }
    }
};

第七章 查找
7.1 Search for a Range (34. Find First and Last Position of Element in Sorted Array)
Given a sorted array of integers, find the starting and ending position of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return [-1, -1].
For example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

/*二分查找两次，找出target的下界跟上界*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(r == nums.size() || nums[r] != target) return res;
        res[0] = r;
        r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target) l = mid + 1;
            else r = mid;
        }
        res[1] = r - 1;
        return res;    
    }
};

/*依然二分查找，一个小trick， 先找target的下界，再找到target+1的下界*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = binarySearch(nums, target);
        if(start == nums.size() || nums[start] != target) return {-1, -1};
        return {start, binarySearch(nums, target + 1) - 1};         
    }

    int binarySearch(vector<int>& nums, int target){
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        }
        return right;
    }
};


7.2 Search Insert Position  (35)
Given a sorted array and a target value, return the index if the target is found. If not, return the index
where it would be if it were inserted in order.
You may assume no duplicates in the array.

/*二分查找*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(target > nums.back()) return nums.size();
        int l = 0, r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target) l = mid + 1;
            else r = mid;
        } 
        return r;   
    }
};
/*O(n) 遍历*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > target) return i;
        }
        return nums.size();    
    }
};


7.3 Search a 2D Matrix (74)
Write an efficient algorithm that searches for a value in an m × n matrix. This matrix has the following
properties:
• Integers in each row are sorted from left to right.
• The first integer of each row is greater than the last integer of the previous row.

/*Binary Search*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m * n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(matrix[mid / n][mid % n] == target) return true;
            else if(matrix[mid / n][mid % n] < target) l = mid + 1;
            else r = mid;
        }
        return false;       
    }
};

/*双指针*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int i = 0, j = matrix[0].size() - 1;
        while(i < matrix.size() && j >= 0){
            if(matrix[i][j] == target) return true;
            else if(matrix[i][j] < target) ++i;
            else --j;
        }        
    }
};


第八章 暴力枚举法
8.1 Subsets  (78)
Given a set of distinct integers, S, return all possible subsets.
Note:
• Elements in a subset must be in non-descending order.
• The solution set must not contain duplicate subsets.
For example, If S = [1,2,3], a solution is:
[
[3],[1],[2],[1,2,3],[1,3],[2,3],[1,2],[]]

/*从上面的二叉树可以观察到，当前层的集合 = 上一层的集合 + 上一层的集合加入当前层处理的元素得到的所有集合（其中树根是空集），因此可以从第二层开始（第一层是空集合）迭代地求最后一层的所有集合（即叶子节点）*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int n = res.size();
            for(int j = 0; j < n; ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;       
    }
};

/*Recursive/DFS 解法*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;    
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(tmp);
            return;
        }
        /*取当前数字*/
        tmp.push_back(nums[pos]);
        dfs(nums, pos + 1, tmp, res);
        tmp.pop_back();
        /*不取当前数字*/
        dfs(nums, pos + 1, tmp, res);
    }

    void dfs2(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        /*不取当前元素*/
        res.push_back(tmp);

        for(int i = pos; i < nums.size(); ++i){
            /*取当前元素*/
            tmp.push_back(nums[i]);
            dfs2(nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
};

8.2 Subsets II (90)
Given a collection of integers that might contain duplicates, S, return all possible subsets.
Note:
Elements in a subset must be in non-descending order. The solution set must not contain duplicate
subsets. For example, If S = [1,2,2], a solution is:
[[2],[1],[1,2,2],[2,2],[1,2],[]]

/*当处理到第一个2时，此时的子集合为 [], [1], [2], [1, 2]，而这时再处理第二个2时，如果在 [] 和 [1] 后直接加2会产生重复，所以只能在上一个循环生成的后两个子集合后面加2，发现了这一点，题目就可以做了，我们用 last 来记录上一个处理的数字，然后判定当前的数字和上面的是否相同，若不同，则循环还是从0到当前子集的个数，若相同，则新子集个数减去之前循环时子集的个数当做起点来循环，这样就不会产生重复了*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res(1);
        sort(nums.begin(), nums.end());
        int pre = nums[0], preSize = 1;
        for(int i = 0; i < nums.size(); ++i){
            if(pre != nums[i]){
                pre = nums[i];
                preSize = res.size();
            }
            int newSize = res.size();
            for(int j = newSize - preSize; j < res.size(); ++j){
                res.push_back(res[j]);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};


/*DFS/RECURSION solution*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        dfs(nums, 0, tmp, res);
        return res;    
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(tmp);
            return;
        }
        while(pos + 1 < nums.size() && nums[pos + 1] == nums[pos]) pos++;
        tmp.push_back(nums[pos]);
        dfs(nums, pos + 1, tmp, res);
        tmp.pop_back();

        dfs(nums, pos + 1, tmp, res);
    }

    void dfs2(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        res.push_back(tmp);
        for(int i = pos; i < nums.size(); ++i){
            if(i > pos && nums[i - 1] == nums[i]) continue;
            tmp.push_back(nums[i]);
            dfs(nums, pos + 1, tm, res);
            tmp.pop_back();
        }
    }
};


8.3 Permutations (46)
Given a collection of numbers, return all possible permutations.
For example, [1,2,3] have the following permutations: [1,2,3], [1,3,2], [2,1,3], [2,3,1],
[3,1,2], and [3,2,1].

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp, visited(nums.size(), 0);
        helper();
        return res;
    }
private:
    void helper(vector<int>& nums, int pos, vector<int>& tmp, vector<vector<int>>& res){
        if(pos == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i]) continue;
            visited[i] = 1;
            tmp.push_back(nums[i]);
            helper(nums, pos + 1, tmp, res);
            tmp.pop_back();
            visited[i] = 0;
        }
    }

    void dfs(vector<int>& nums, vector<int>& tmp, vector<vector<int>>& res){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return;
        }
        for(auto num : nums){
            auto pos = find(tmp.begin(), tmp.end(), num);
            if(pos == tmp.end()){
                tmp.push_back(num);
                dfs(nums, tmp, res);
                tmp.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return vector<vector<>>(1, vector<int>());
        vector<vector<int>> res;
        int first = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> words = permute(nums);
        for(auto & a: words){
            for(int i = 0; i <= a.size(); ++i){
                a.insert(a.begin + i, first);
                res.push_back(a);
                a.erase(a.begin + i);
            }
        }
        return res;
    }
}

8.3.1 next_permutation (31)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
    }
};

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
    }
};

8.4 Permutations II (47)
Given a collection of numbers that might contain duplicates, return all possible unique permutations.
For example, [1,1,2] have the following unique permutations: [1,1,2], [1,2,1], and [2,1,1].
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp, visited(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, visited, tmp, res);
        return;    
    }
private:
    void dfs(vector<int>& nums, int pos, vector<int>& visited, vector<int>& tmp, vector<vector<int>>& res){
        if(tmp.size() == nums.size()){
            res.push_back(tmp);
            return res;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i]) continue;
            if(i > 0 && nums[i - 1] == nums[i] && visited[i] == 0) continue;
            visited[i] = 1;
            tmp.push_back(nums[i]);
            dfs(nums, i + 1, visited, tmp, res);
            tmp.pop_back(nums[i]);
            visited[i] = 0;
        }
    }
};
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permute(nums, 0, res);
        return res;        
    }
private:
    void permute(vector<int>& nums, int start, vector<vector<int>>& res){
        if(start >= nums.size()) res.push_back(nums);
        for(int i = start; i < nums.size(); ++i){
            if(i != start && nums[i] == nums[start]) continue;
            swap(nums[i], nums[start]);
            permute(nums, start + 1, res);
        }
    }
};

8.5 Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1...n.
For example, If n = 4 and k = 2, a solution is:

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        
        helper(n, k, 1, res, tmp);
        return res;
    }
private:
    void helper(int n, int k, int pos, vector<vector<int>>& res, vector<int>& tmp){
        if(tmp.size() == k){
            res.push_back(tmp);
            return;
        }
        
        for(int i = pos; i <= n; ++i){
            tmp.push_back(i);
            helper(n, k, i + 1, res, tmp);
            tmp.pop_back();
        }
    }
};

8.6 Letter Combinations of a Phone Number
Given a digit string, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res;
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        dfs(digits, dict, 0, "", res);
        return res;        
    }
private:
    void dfs(string& digits, vector<string>& dict, int pos, string out, vector<string>& res){
        if(pos == digits.size()) {res.push_back(out); return;}
        string str = dict[digits[pos] - '0'];
        for(int i = 0; i < str.size(); ++i){
            dfs(digits, dict, pos + 1, out + str[i], res);
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> res{""};
        vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        for(int i = 0; i < digits.size(); ++i){
            vector<string> t;
            string str = dict[digits[i] - '0'];
            for(int j = 0; j < str.size(); ++j){
                for(string s : res)
                    t.push_back(s + str[j]);
            }
            res = t;
        }
        return res;
    }
};


第九章 广度优先搜索
9.1 Word Ladder  (127)
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence
from start to end, such that:
• Only one letter can be changed at a time
• Each intermediate word must exist in the dictionary
For example, Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", return its length 5.
Note:
• Return 0 if there is no such transformation sequence.
• All words have the same length.
• All words contain only lowercase alphabetic characters.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;
        queue<string> q{{beginWord}};
        int res = 0;
        while(!q.empty()){
            for(int k = q.size(); k >=0; --k){
                string word = q.front(); q.pop();
                if(word == endWord) return res + 1;
                for(int i = 0; i < word.size(); ++i){
                    string newword = word;
                    for(char c = 'a'; c <= 'z'; ++c){
                        newword[i] = c;
                        if(wordSet.count(newword) && newword != word){
                            q.push(newword);
                            wordSet.erase(newword);
                        }
                    }
                }
            }
            ++res;
        }
        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(!wordSet.count(endWord)) return 0;
        unordered_map<string, int> pathCnt{{beginWord, 1}};
        queue<string> q{{beginWord}};
        while(!q.empty()){
            string word = q.top(); q.pop();
            for(int i = 0; i < word.size(); ++i){
                string newword = word;
                for(char c = 'a'; c <= 'z'; ++c){
                    newword[i] = c;
                    if(neword == endword) return pathCnt(word) + 1;
                    if(wordSet.count(newword) && pathCnt.count(newword))){
                        q.push(newword);
                        pathCnt[newword] = pathCnt[word] + 1;
                    }
                }
            }
        }
        return 0;        
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*Bidirectional*/
        if(wordList.empty()) return 0;
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        int count = 0;
        while(!s1.empty() and !s2.empty()){
            count++;
            if(s1.size() > s2.size()){
                swap(s1, s2);
            }
            unordered_set<string> tmp;
            for(auto s: s1){
                for(int i = 0; i < s.size(); i++){
                    char old = s[i];
                    for(char c = 'a'; c <='z'; c++){
                        s[i] = c;
                        if(s2.count(s)) return count+1;
                        if(dict.count(s)){
                            dict.erase(s);
                            tmp.insert(s);
                        }
                    }
                    s[i] = old;
                }
            }
            s1 = tmp;
        }
        return 0;
    }
};


9.2 Word Ladder II (126)

Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start
to end, such that:
• Only one letter can be changed at a time
• Each intermediate word must exist in the dictionary

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};
        dict.erase(beginWord);
        dict.erase(endWord);
        vector<string> start{beginWord};
        queue<vector<string>> q;
        q.push(start);
        while(!q.empty()){
            if(!res.empty()) return res;
            for(int k = q.size(); k > 0; --k){
                vector<string> tmp = q.front(); q.pop();
                string word = tmp.back();
                dict.erase(word);
                if(word == endword) res.push_back(tmp);
                for(int i = 0; i < word.size(); ++i){
                    string newword = word;
                    for(int c = 'a'; c <= 'z'; ++c){
                        newword[i] = c;
                        if(dict.count(newword)){
                            tmp.push_back(newword);
                            q.push(tmp);
                            tmp.pop_back();
                        }
                    }
                }
            }
        }
        return res;        
    }
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
    }
};


9.3 Surrounded Regions (130)
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region .
For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:
X X X X
X X X X
X X X X
X O X X

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 || i == m - 1 || j == 0 || j == n - 1 && board[i][j] == 'O')
                    dfs(board, i, j);
            }
        }
    }
private:
    void dfs(vector<vector<char>>& board, int m, int n){
        if(m < 0 || m >= board.size() || n < 0 || n > board[0].size()) return;
        if(baord[m][n] != 'O') return;
        board[m][n] = 'A';
        dfs(board, m + 1, n);
        dfs(board, m - 1, n);
        dfs(board, m, n + 1);
        dfs(board, m, n - 1);
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if((i == 0 || i == m - 1 || j == 0 || j == n - 1) && board[i][j] == 'O'){
                    board[i][j] = 'A';
                    queue<vector<int>> q{{i, j}};
                    while(!q.empty()){
                        vector<int> tmp = q.front(); q.pop();
                        if(tmp[0] >= 1 && board[tmp[0] - 1][tmp[1]] == 'O') { board[tmp[0] -1][tmp[1]] = 'A'; q.push({tmp[0] - 1, tmp[1]});}
                        if(tmp[0] + 1 < m && board[tmp[0] + 1][tmp[1]] == 'O') {board[tmp[0] + 1][tmp[1]] = 'A'; q.push({tmp[0] + 1, tmp[1]});}
                        if(tmp[1] >= 1 && board[tmp[0]][tmp[1] - 1] == 'O') { board[tmp[0]][tmp[1] - 1] = 'A'; q.push({tmp[0], tmp[1] - 1});}
                        if(tmp[1] + 1 < n && board[tmp[0]][tmp[1] + 1] == 'O') {board[tmp[0]][tmp[1] + 1] = 'A'; q.push({tmp[0], tmp[1] + 1});}
                    }
                }
            }
        }
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == 'A') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};


第十章 深度优先搜索
10.1 Palindrome Partitioning  (131)

Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.
For example, given s = "aab", Return
[
["aa","b"],
["a","a","b"]
]

class Solution {
public:
    bool isPalindrome(string s, int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        int n = s.size();
        vector<vector<string>> res;
        vector<string> tmp;
        function<void(int)> dfs = [&](int start){
            if(start = n){
                res.push_back(tmp);
                return;
            }
            for(int i = start; i < s.size(); ++i){
                if(!isPalindrome(s, start, i)) continue;
                tmp.push_back(s.substr(start, i - start + 1));
                dfs(i + 1);
                tmp.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};

class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        n = s.size();
        vector<vector<string>> res;
        vector<string> tmp;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(s[i] == s[j] && (i - j <= 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }

    }
private:
    void helper(string s, int start, vector<vector<bool>> dp, vector<string>& tmp, vector<vector<string>>& res){
        if(start = s.size()){
            res.push_back(tmp);
            return;
        }

        for(int i = start; i < s.size(); ++i){
            if(!dp[start][i]) continue;
            tmp.push_back(s.substr(start, i - start + 1));
            helper(s, i + 1, dp, tmp, res);
            tmp.pop_back();
        }
    }
};

/*DP solution*/
class Solution {
public:
    vector<vector<string>> partition(string s) {
        if(s.empty()) return {};
        int n = s.size();
        vector<vector<vector<string>>> res(n + 1); //3维数组，res[i] 表示0--i的回文组合
        vector<vector<bool>> dp(n, vector<bool>(n));
        res[0].push_back({});
        for(int i = 0; i < n; ++i){
            for(int j = 0; j <= i; ++j){
                if(s[j] == s[i] && (i - j <= 2 || dp[j + 1][i - 1])){
                    dp[j][i] = true;
                    string cur = s.substr(j, i - j + 1);
                    for(auto arr : res[j]){
                        arr.push_back(cur);
                        res[i + 1].push_back(arr);
                    }
                }
            }
        }
        return res[n];
    }
}


10.2 Unique Path (62)
A robot is located at the top-left corner of a m × n grid (marked ’Start’ in the diagram below).
The robot can only move either down or right at any point in time. The robot is trying to reach the
bottom-right corner of the grid (marked ’Finish’ in the diagram below).
How many possible unique paths are there?

class Solution {
public:
    int uniquePaths(int m, int n) {
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        dp[0][0] = 1;
        return dfs(m - 1, n -1);   
    }
private:
    vector<vector<int>> dp; //dp[i][j] 表示 0,0到i,j的路径条数

    int dfs(int x, int y){
        if(x < 0 || y < 0) return 0;
        if(x == 0 && y == 0) return dp[0][0];
        if(dp[x][y] > 0)
            return dp[x][y];
        else
            return dp[x][y] = dfs(x - 1, y) + dfs(x, y - 1); 
    }
};

/*动态规划 + 滚动数组*/
/*dp[i][j] = dp[i - 1][j] + dp[i][j - 1]*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return f[n - 1];
    }
};

/*2D-DP*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) dp[i][0] = 1;
        for(int j = 0; j < n; ++j) dp[0][j] = 1;
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n -1]; 
    }
};

10.3 Unique Paths II  (63)
Follow up for ”Unique Paths”:
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3 × 3 grid as illustrated below.
[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.
Note: m and n will be at most 100.
/*dfs + memo*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        memo = vector<vector<int>>(m, vector<int>(n, 0));
        if(obstacleGrid[0][0] || obstacleGrid[m - 1][n - 1]) return 0;
        memo[0][0] = 1;
        return dfs(obstacldGrid, m - 1, n - 1);    
    }
private:
    vector<vector<int>> memo;
    int dfs(vector<vector<int>>& obstacleGrid, int x, int y){
        if(x < 0 || y < 0) return 0;
        if(x == 0 && y == 0) return 1;
        if(obstacldGrid[x][y]) return 0;
        if(memo[x][y] > 0) return memo[x][y];
        return memo[x][y] = dfs(obstacleGrid, x - 1, y) + dfs(obstacleGrid, x, y - 1);
    }
};

/*dp + 滚动数组*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0]) return 0;
        vector<int> dp(n);
        dp[0] = 1;
        for(int i = 0; i < m; ++i){
            dp[0] = dp[0] == 0 ? 0 : obstacleGrid[i][0] ? 0 : 1;
            for(int j = 1; j < n; ++j){
                dp[j] = obstacleGrid[i][j] ? 0 : dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];    
    }
};

10.4 N-queens  (51)
The n-queens puzzle is the problem of placing n queens on an n × n chessboard such that no two queens
attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.'
both indicate a queen and an empty space respectively.
For example, There exist two distinct solutions to the 4-queens puzzle:
[
[".Q..", // Solution 1
"...Q",
"Q...",
"..Q."],
["..Q.",
 // Solution 2
"Q...",
"...Q",
".Q.."]
]

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(0, board, res);
        return res;        
    }
private:
    void dfs(int row, vector<string>& board, vector<vector<string>>& res){
        int n = board.size();
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int i = 0; i < n; ++i){
            if(isValid(board, row, i)){
                board[row][i] = 'Q';
                dfs(row + 1, board, res);
                board[row][i] = '.';
            }
        }
    }

    bool isValid(vector<string> board, int row, int col){
        for(int i = 0; i < row; ++i){
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row -1, j = col - 1; i >= 0 && j >= 0; --i, --j){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.size(); --i, ++j){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
    }
};


10.5 N-Queens II  (52)
Follow up for N-Queens problem.
Now, instead outputting board configurations, return the total number of distinct solutions.

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cur(n, -1);  //表示第i行，q的位置cur[i];
        this.count = 0;
        dfs(cur, 0);
        return count;    
    }
private:
    int count;
    void dfs(vector<int>& cur, int row){
        if(row == cur.size()){
            count++; return;
        }
        for(int j = 0; j < cur.size(); ++j){
            if(!isValid(cur, row, j)) continue;
            cur[row] = j;
            dfs(cur, row + 1);
            cur[row] = -1;
        }
    }

    bool isValid(vector<int>& cur, int row, int col){
        for(int i = 0; i < row; ++i){
            /*同一列上*/
            if(cur[i] == col) return false;
            /*同一对角线上*/
            if(abs(i - row) == abs(cur[i] - col)) return false;
        }
        return true;
    }
};

class Solution {
public:
    int totalNQueens(int n) {
        
    }
};


10.6 Restore IP Addresses (93)
Given a string containing only digits, restore it by returning all possible valid IP address combinations.
For example: Given "25525511135",
return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        dfs(s, 0, "", res);
        return res;    
    }
private:
    bool isValid(string s){
        if(s.empty() || s.size() > 3 || (s.size() > 1 && s[0] = '0')) return false;
        int res = atoi(s.c_str());
        return res >= 0 && res <= 255;
    }

    void dfs(string s, int pos, string out, vector<string>& res){
        if(pos == 4){
            if(s.empty()){
                res.push_back(out);
                return;
            }
        }
        for(int i = 1; i <= 3; ++i){
            if(s.size() >= i && isValid(s.substr(0, i)))
                dfs(s.substr(i), pos + 1, out + s.substr(0, i) + (pos == 3 ? "" : "."), res);
        }
    }
};


10.7Combination Sum (39)
Given a set of candidate numbers (C) and a target number (T ), find all unique combinations in C where
the candidate numbers sums to T .
The same repeated number may be chosen from C unlimited number of times.
Note:
• All numbers (including target) will be positive integers.
• Elements in a combination (a1, a2 , ..., ak ) must be in non-descending order. (ie, a1 ≤ a2 ≤ ... ≤ ak ).
• The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, A solution set is:
[7]
[2, 2, 3]

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(canditates, target, 0, out, res);
        return res;
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(out);
            return;
        }
        for(int i = start; i < canditates.size(); ++i){
            out.push_back(canditates[i]);
            dfs(canditates, target - canditates[i], i, out, res);
            out.pop_back();
        }
    }    
};

10.8 Combination Sum II (40)
Given a collection of candidate numbers (C) and a target number (T ), find all unique combinations in
C where the candidate numbers sums to T .
Each number in C may only be used once in the combination.
Note:
• All numbers (including target) will be positive integers.
• Elements in a combination (a1, a2 , ..., ak ) must be in non-descending order. (ie, a1 > a2 > ... > ak ).
• The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, A solution set is:
[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6]

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>  res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, out, res);
        return res;     
    }
private:
    void dfs(vector<int>& candidates, int target, int start, vector<int>& out, vector<vector<int>>& res){
        if(target < 0) return;
        if(target == 0){
            res.push_back(out); return;
        }
        for(int i = start; i < candidates.size(); ++i){
            if(i > start && candidates[i] == candidates[i - 1]) continue;
            out.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i + 1, out, res);
            out.pop_back();
        }
    }
};

10.9 Generate Parentheses (22)
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
For example, given n = 3, a solution set is:
"((()))", "(()())", "(())()", "()(())", "()()()"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(n, n, "", res);
        return res;
    }
private:
    /*l, r 代表剩余的左括号，右括号数量*/
    void helper(int l, int r, string out, vector<string>& res){
        if(l > r) return;
        if(l == 0 && r == 0){
            res.push_back(out);
            return;
        }
        if(l > 0) helper(l - 1, r, out + '(', res);
        if(r > 0) helper(l, r - 1, out + ')', res);
    }
};

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if(n == 0) return vector<string>(1, "");
        if(n == 1) return vector<string>(1, "()");
        vector<string> res;
        for(int i = 0; i < n; ++i){
            for(auto inner : generateParenthesis(i)){
                for(auto outer : generateParenthesis(n - 1 - i))
                    result.push_back("(" + inner + ")" + outer);
            }
        }
    }
};


10.10 Sudoku Solver  (37)
Write a program to solve a Sudoku puzzle by filling the empty cells.
Empty cells are indicated by the character '.'.
You may assume that there will be only one unique solution.

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board, 0, 0);    
    }
private:
    bool isValid(vector<vector<char>>& board, int i, int j, int val){
        for(int k = 0; k < 9; ++k){
            if(board[k][j] != '.' && board[k][j] == val) return false;
            if(board[i][k] != '.' && board[i][k] == val) return false;
            int row = i / 3 * 3 + k / 3, col = j / 3 * 3 + k % 3;
            if(board[row][col] != '.' && board[row][col] == val) return false;
        }
        return true;
    }

    bool helper(vector<vector<char>>& board, int i, int j){
        if(i == 9) return true;
        if(j >= 9) return helper(board, i + 1, 0);
        if(board[i][j] == '.') return helper(board, i, j + 1);
        for(char c = '1'; c <= '9'; ++c){
            if(!isValid(board, i, j, c)) continue;
            board[i][j] = c;
            if(helper(board, i, j + 1)) return true;
            board[i][j] = '.';
        }
        return false;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
    }
private:
    bool helper(vector<vector<char>>& board){
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] == '.') continue;
                for(char c = '1'; c <= '9'; ++c){
                    if(!isValid(baord, i, j, c)) continue;
                    board[i][j] = c;
                    if(helper(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;   
    }
};


10.11 Word Search (79)
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those
horizontally or vertically neighbouring. The same letter cell may not be used more than once.
For example, Given board =
[["ABCE"],
["SFCS"],
["ADEE"]]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j>){
                if(helper(board, word, 0, x, y, visited)) return true;
            }
        }
        return false;    
    }
private:
    bool helper(vector<vector<char>>& board, string word, int index, int x, int y, vector<vector<bool>>& visited){
        if(index == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if(x < 0 || y < 0 || x >= m || y = n || visited[x][y] || board[x][y] != word[index]) return false;
        visited[x][y] = true;
        bool res = helper(board, word, index + 1, x + 1, y, visited)
                || helper(board, word, index + 1, x - 1, y, visited)
                || helper(board, word, index + 1, x, y + 1, visited)
                || helper(board, word, index + 1, x, y - 1, visited);
        visited[x][y] = false;
        return res;
    }
};


第11章 分治法
11.1 Pow(x,n)  (50)
Implement pow(x, n).

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)  return 1.0;
        if(x == 1) return 1.0;
        if(n == INT_MIN){
            n /= 2;
            x *= x;
        }
        if(n < 0){
            x = 1 / x;
            n = -n;
        }
        return n % 2 == 0 ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);       
    }
};

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i /= 2){
            if(i % 2) res *= x;
            x *= x;
        }
        return n > 0 ? res : 1 / res;
    }
};


11.2 Sqrt(x)  (69)
Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
Example 1:
Input: 4
Output: 2

class Solution {
public:
    int mySqrt(int x) {
        if(x <= 1) return x;
        int left = 0, right = x;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(x / mid >= mid) l = mid + 1;
            else r = mid;
        }
        return r - 1;
    }
};


第12章 贪心算法

12.1 Jump Game (55)
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Determine if you are able to reach the last index.
For example:
A = [2,3,1,1,4], return true.
A = [3,2,1,0,4], return false.

/*DP solution: dp[i]表示在i位置剩余的跳力*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if(dp[i] < 0) return false;
        }
        return true;        
    }
};

/*Greedy; reach 表示最远能达到的位置。*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size(), reach = 0;
        for(int i = 0; i < n; ++i){
            if(i > reach || reach >= n - 1) break;
            reach = max(reach, i + nums[i]);
        }
        return reach >= n - 1;
    }
};

12.2 Jump Game II (45)
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example: Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps
to the last index.)


12.3 Best Time to Buy and Sell Stock (121)
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, buy = INT_MAX;
        for(int price : prices){
            buy = min(buy, price);
            res = max(res, price - buy);
        }
        return res;        
    }
};

12.4 Best Time to Buy and Sell Stock II  (122)
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
on each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

/*贪心算法： 可以用类似滑窗的方法找到下个连续上升的价格序列的第一个值，然后找到其最后一个值，求出差值，然后重复这样的操作。不过写起来麻烦。下面的写法：如果今天的价格高于昨天的价格，就在昨天买入，今天卖出。相当于将一个波峰的上升沿拆解成许多个以天为单位的上升期。*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(prices[i] > prices[i - 1])
                max += prices[i] - prices[i - 1];
        }
        return max;    
    }
};

/*暴力法*/
class Solution {
public:
    vector<int> profits;
    int maxProfit(vector<int>& prices) {
        solve(0, false, 0, prices);
        int profitMax = 0;
        for(int profit : profits){
            profitMax = max(profitMax, profit);
        }
        return profitMax;
    }
    void solve(int index, bool have, int profitSum, vector<int>& prices){
        if(index >= prices.size()){
            profits.push_back(profitSum);
            return;
        }
        if(have){ /*持有*/
            solve(index + 1, false, profitSum + prices[index], prices);  //卖出
            solve(index + 1, true, profitSum, prices); //继续持有
        }
        else{ /*未持有*/
            solve(index + 1, false, profitSum, prices);  //继续未持有
            solve(index + 1, true, profitSum - prices[index], prices);
        }
        return; 
    }
};

/*DP 解法*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        /*dp[i][0]表示第i天不持有股票的最大利润，dp[i][1]表示第i天持有股票的最大利润*/
        dp[0][0] = 0; dp[0][1] = -prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][0] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};


12.4.1 Best Time to Buy and Sell Stock III  (123)
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        size_t n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0][2] = -prices[0]; dp[0][3] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return dp[n - 1][3];
    }
};


12.5
Longest Substring Without Repeating Characters  (3)

Given a string, find the length of the longest substring without repeating characters. For example, the
longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the
longest substring is "b", with the length of 1.

/*Sliding Window*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1;
        vector<int> m(128, -1);
        for(int i = 0; i < s.size(); ++i){
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
}

/*Brute Force. O(n2)*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 1;
        for(int i = 0; i < s.size() - 1; ++i){
            set<int> st;
            st.insert(s[i]);
            for(int j = i + 1; j < s.size(); ++j){
                if(!st.insert(s[j]).second){
                    res = max(res, st.size());
                    break;
                }
            }
        }
        return res;
    }
}


12.6 Container With Most Water  (11)
Given n non-negative integers a1 , a2 , ..., an , where each represents a point at coordinate (i, ai). n verti-
cal lines are drawn such that the two endpoints of line i is at (i, ai ) and (i, 0). Find two lines, which together
with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container.

class Solution {
public:
    int maxArea(vector<int>& height) {
        
    }
};


第 13 章 动态规划

13.1 Triangle
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent
numbers on the row below.
For example, given the following triangle
[[2],
[3,4],
[6,5,7],
[4,1,8,3]]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of
rows in the triangle.
/*DP: modified the triangle*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*triangle[i][j] 表示从i,j点到达bottom的最小 sum*/
        for(int i = triangle.size() - 2; i >= 0; --i){
            for(int j = 0; j < triangle[i].size(); ++j){
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];    
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        /*dp[i][j] 表示从i,j点到达bottom的最小 sum*/
        vector<int> dp(triangle.back());
        for(int i = triangle.size() - 2; i >= 0; ++i){
            for(int j = 0; j < triangle[i].size(); ++j){
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
    }
};

13.2 Maximum Subarray  (53)
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] has
the largest sum = 6

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, res = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            /*数组中的元素要么选择加入，要么自己单独开始*/
            sum = max(sum + nums[i], nums[i]);
            res = max(sum, res);
        }
        return res;
    }
};

/*Divid Conquer*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        return DividConquer(nums, 0, nums.size() - 1);
    }
private:
    int DividandConuqer(vector<int>& nums, int l, int r){
        if(l >= r) return nums[l];
        int mid = l + (r - l) / 2;
        int lmax = DividandConquer(nums, l, mid - 1);
        int rmax = DividandConquer(nums, mid + 1, r);
        int mmax = nums[mid], t = mmax;
        for(int i = mid - 1; i >= l; --i){
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for(int i = mid + 1; i <= r; ++i){
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(lmax, rmax));
    }
};

13.3 Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.
For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

class Solution {
public:
    int minCut(string s) {
        if(s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> isP(n, vector<bool>(n));
        vector<int> dp(n);
        for(int i = 0; i < n; ++i){
            dp[i] = i;
            for(int j = 0; j <= i; ++j){
                if(s[i] == s[j] && (i - j < 2 || isP[j + 1][i - 1])){
                    isP[j][i] = true;
                    dp[i] = (j == 0 ? 0 : min(dp[i], dp[j - 1] + 1));
                }
            }
        }
        return dp[n - 1];
    }
};


13.4 Maximal Rectangle
Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return
its area.
Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        /*把每一行可以看做84题的一个直方图*/
        if(matrix.empty() || matrix[0].empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> heights(n + 1);
        for(int i = 0; i < m; ++i){
            stack<int> s;
            for(int j = 0; j < n; ++j){
                if(j < n)
                    heights[j] = matrix[i][j] == 1 ? heights[j] + 1 : 0;
                while(!s.empty() && heights[s.top()] >= heights[j]){
                    int cur = s.top(); s.pop();
                    res = max(res, heights[cur] * ( s.empty() ? 0 : (j - s.top() - 1)))
                }
                s.push(j);
            }
        }
        return res;
    }
};


13.5 Best Time to Buy and Sell Stock III (123)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        /*dp[i][0]代表第i轮持有1的最大收益，dp[i][1]表示第i轮卖出1的最大收益*/
        /*dp[i][2]代表第i轮持有2的最大收益，dp[i][3]表示第i轮卖出2的最大收益*/
        dp[0][0] = -prices[0]; dp[0][1] = 0; dp[0]][2] = -prices[0]; dp[0][3] = 0;
        for(int i = 1; i < n; ++i){
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] - prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][2] + prices[i], dp[i - 1][3]);
        }
        return dp[n - 1][3];
    }
};

13.6 Interleaving String  (97)
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
For example, Given: s1 = "aabcc", s2 = "dbbca",
When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length()) return false;
        int m = s1.length(), n = s2.length();
        vector<vector<bool>> dp(m, vector<bool>(n, flase));
        dp[0][0] = true;
        for(int i = 1; i <= m; ++i){
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }
        for(int j = 1; j <= n; ++j){
            dp[0][j] = dp[0][j] && s2[j - 1] == s3[j - 1];
        }
        /*如果s3最后一个字符是s1的，dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1].
          如果s3最后一个字符是s2的，dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]*/
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[m][n];
    }
};


13.7 Scramble String  (87)
Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1
/*Recursion will be TLE*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        string str1 = s1, str2 = s2;
        sort(str1.begin(), str1.begin());
        sort(str2.begin(), str2.begin());
        if(str1 != str2) return false;
        for(int i = 0; i < str1.size(); ++i){
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
            s21 = s2.substr(s1.size() - i);
            s22 = s2.substr(0, s1.size() - i);
            if(isScramble(s11, s21) && isScramble(s12, s22)) return true;
        } 
        return false;   
    }
};

/*dp Solution*/
class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        int n = s1.size();
        /*dp[i][j][len]表示从s1的i位置，s2的j位置开始长度为len时是否为scramble*/
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n + 1)));
        for(int len = 1; len <= n; ++len){
            for(int i = 0; i <= n - len; ++i){
                for(int j = 0; j <= n - len; ++j){
                    if(len == 1)
                        dp[i][j][len] = s1[i] == s2[j];
                    else{
                        for(int k = 1; k <= len; ++k){
                            if((dp[i][j][k] && dp[i + k][j + k][len - k]) || (dp[i + k][j][len - k] &&  dp[i][j + len - k][k])
                            dp[i][j][len] = true;
                        }
                    }
                }
            }
        }
        return dp[0][0][n];        
    }
};


13.8 Minimum Path Sum (64)
Given a m × n grid filled with non-negative numbers, find a path from top left to bottom right which
minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time

/*DP solution*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(gird.empty() || grid[0].empty()) return 0;
        size_t m = gird.size(), n = gird[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < m; ++i) dp[i][0] = dp[i - 1][0] + grid[i][0];
        for(int j = 1; j < n; ++j) dp[0][j] = dp[0][j - 1] + grid[0][j];
        for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};


13.9 Edit Distance  (72)
Given two words word1 and word2, find the minimum number of steps required to convert word1 to
word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
• Insert a character
• Delete a character
• Replace a character

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(i == 0 && j == 0) dp[0][0] = 0;
                else if(i == 0) dp[0][j] = j;
                else if(j == 0) dp[i][0] = i;
                else{
                    if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

13.10 Decode Ways  (91)
A message containing letters from A-Z is being encoded to numbers using the following mapping:
'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.
For example, Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
The number of ways decoding "12" is 2.

/*Recursion + memo*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        memo[""] = 1;
        return helper(s);                    
    }
private:
    unordered_map<string, int> memo;
    int helper(string s){
        if(memo.count(s)) return memo[s];
        if(s[0] == '0') return 0;
        if(s.length() == 1) return 1;
        int res = helper(s.substr(1));
        if(stoi(s.substr(0, 2)) <= 26)
            res += helper(s.substr(2));
        memo[s] = res;
        return res;
    }
};
/*用index 代替数组的拷贝*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        return helper(s, 0, s.length() - 1);                
    }
private:
    unordered_map<int, int> memo;
    int helper(string s, int l, int r){
        if(memo.count(l)) return memo[l];
        if(s[l] == '0') return 0;
        if(l >= r) return 1;

        int res = helper(s, l + 1, r);
        const int index = 10 * (s[l + 1] - '0') + (s[l + 2] - '0');
        if(index <= 26)
            res += helper(s, l + 2, r);
        memo[l] = res;
        return res;
    }
};

/*DP*/
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        size_t n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int i = 1; i < dp.size(); ++i){
            dp[i] = s[i - 1] == '0' ? 0 : dp[i - 1];
            if(i > 1 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')))
                dp[i] += dp[i - 2];
        }
        return dp[n];            
    }
};


13.11 Distinct Subsequences  (115)
Given a string S and a string T , count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by deleting some (can
be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is
a subsequence of "ABCDE" while "AEC" is not).

/*DP solution*/
class Solution {
public:
    int numDistinct(string s, string t) {
        size_t m = s.size(), n = t.size();
        /*dp[i][j] 表示s的0-j 中包含t的0-i的subsequence的数量*/
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        fill(dp[0].begin(), dp[0].end(), 1);
        for(size_t i = 1; i <= n; ++i){
            for(size_t j = 1; j <= m; ++j){
                dp[i][j] = dp[i][j - 1] + (s[j - 1] == t[i - 1] ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp[n][m];        
    }
};

/*Recursion + memo*/
class Solution {
public:
    int numDistinct(string s, string t) {
        size_t m = s.length(), n = t.length();
        memo = vector<vector<unsigned long long>>(m, vector<unsigned long long>(n, -1));
        return helper(0, 0, s, t);
    }
private:
    vector<vector<unsigned long long>> memo;
    int helper(int i, int j, string s, string t){
        if(memo[i][j] != -1) return memo[i][j];
        if(j >= t.length()) return 1;
        if(i >= s.length()) return 0;

        int res = helper(i + 1, j, s, t);
        if(s[i] == t[j])
            res += helper(i + 1, j + 1, s, t);
        memo[i][j] = res;
        return res;
    }
};


13.12 Word Break  (139)
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated
sequence of one or more dictionary words.
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
/*DP solution*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        size_t n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i){
            for(int j = i - 1; j >= 0; --j){
                if(dp[j] && dict.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];    
    }
};

/*Recursion + memo*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        size_t n = s.length();
        memo = vector<int>(n, -1);
        return helper(s, dict, 0);    
    }
private:
    vector<bool> memo;
    bool helper(string s, vector<string> dict, int start){
        if(memo[start] != -1) return memo[start];
        if(start >= s.size()) return true;
        for(int i = start + 1; i < s.size(); ++i){
            if(dict.count(s.substr(start, i - start)) && helper(s, dict, i))
                memo[start] = 1;
        }
        return memo[start] = 0;
    }
};


13.13 Word Break II  (140)

Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word
is a valid dictionary word.
Return all such possible sentences.
For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].
A solution is ["cats and dog", "cat sand dog"].


class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<string>> mp;
        return helper(s, wordDict, mp);
    }
private:
    vector<string> helper(string s, vector<string> wordDict, unordered_map<string, vector<string>>& mp){
        if(mp.count(s)) return mp[s];
        if(s.empty()) return {""};
        vector<string> res;
        for(string word : wordDict){
            if(s.substr(0, word.length()) != word) continue;
            vector<string> tmp;
            tmp = helper(s.substr(word.length()), wordDict, mp);
            for(string t : tmp){
                res.push_back(word + (t.empty() ? "" : " ") + t);
            }
        }
        memo[s] = res;
    }
};


House robber  (198)
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        int res = 0;
        /*dp[i][0] 表示不抢， dp[i][1]表示抢*/
        vector<vector<int>> dp(nums.size() + 1, vector<int>(2, 0));
        for(int i = 1; i <= nums.size(); ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1]; /*注意这里nums[i - 1]因为i是从1开始。对应nums里为i - 1*/
        }
        return max(dp[nums.size()][0], dp[nums.size()][1]);
    }
};


House Robber II (213)
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

class Solution {
public:
    int rob(vector<int>& nums) {
        int res;
        if(nums.size() <= 1) return nums.size() == 0 ? 0 : nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        vector<vector<int>> dp(nums.size(), vector<int>(2, 0));
        vector<vector<int>> dp2(nums.size(), vector<int>(2, 0));
        /*去掉最后一个元素*/
        for(int i = 1; i <= nums.size() - 1; ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i - 1]; 
        }
        int m1 = max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
        
        /*去掉第一个元素*/
        for(int i = 2; i <= nums.size(); ++i){
            dp2[i][0] = max(dp2[i - 1][0], dp2[i - 1][1]);
            dp2[i][1] = dp2[i - 1][0] + nums[i - 1];
        }
        int m2 = max(dp2[nums.size()][0], dp2[nums.size()][1]);
        return max(m1, m2);
    }
};



第 14 章 图
struct undirectedGraph{
    int label;
    vector<undirectedGraph*> neighbors;
    undirectedGraph(int x): label(x) {};
}

14.1 Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbours.
OJ’s undirected graph serialization: Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbour of the
node. As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
2. Second node is labeled as 1. Connect node 1 to node 2.
3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
   1
  / \
 /   \
0 --- 2
     / \
     \_/



第 15 章 细节实现题

15.1 ReverseInteger  (7)

在贴出答案的同时，OJ 还提了一个问题 To check for overflow/underflow, we could check if ret > 214748364 or ret < –214748364 before multiplying by 10. On the other hand, we do not need to check if ret == 214748364, why? （214748364 即为 INT_MAX / 10)

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            /*判断整数溢出的方法*/
            if(abs(res) > INT_MAX / 10) return 0;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;        
    }
};

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        while(x){
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res > INT_MAX || res < INT_MIN ? 0 : res;
    }
};


15.2 Palindrome Number (9)
Determine whether an integer is a palindrome. Do this without extra space.
Some hints:
Could negative integers be palindromes? (ie, -1)
If you are thinking of converting the integer to string, note the restriction of using extra space.
You could also try reversing an integer. However, if you have solved the problem ”Reverse Integer”,
you know that the reversed integer might overflow. How would you handle such case?
There is a more generic way of solving this problem

/*要验证回文数，那么就需要看前后半段是否对称，如果把后半段翻转一下，就看和前半段是否相等就行了。所以做法就是取出后半段数字，进行翻转，具体做法是，每次通过对 10 取余，取出最低位的数字，然后加到取出数的末尾，就是将 revertNum 乘以 10，再加上这个余数，这样翻转也就同时完成了，每取一个最低位数字，x都要自除以 10。这样当 revertNum 大于等于x的时候循环停止。由于回文数的位数可奇可偶，如果是偶数的话，那么 revertNum 就应该和x相等了；如果是奇数的话，那么最中间的数字就在 revertNum 的最低位上了，除以 10 以后应该和x是相等的*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int half = 0;
        while(x > half){
            half = 10 * half + x % 10;
            x /= 10;
        }
        return half == x || half / 10 == x;        
    }
};

/*果是 palindrome，反转后仍是原数字，就不可能溢出，只要溢出一定不是 palindrome 返回 false 就行。可以参考 Reverse Integer 这题，直接调用 Reverse()*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 10 || (x % 10 == 0 && x != 0)) return false;
        return reverse(x) == x;
    }
private:
    int reverse(int x){
        int res = 0;
        while(x){
            if(abs(res) > INT_MAX / 10) return -1;
            res = res * 10 + x % 10;
            x /= 10;
        }
        return res;
    }
};

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0)) return false;
        int div = 1;
        while(x / div >= 10)  div *= 10;
        while(x > 0){
            int l = x / div;
            int r = x % 10;
            if(l != r) return false;
            x = x % div / 10;
            div /= 100;
        }
        return true;
    }
}


15.3 Insert Interval (57)

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
You may assume that the intervals were initially sorted according to their start times.
Example 1: Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as
[1,2],[3,10],[12,16].
This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

/*遍历intervals, 先把不相交的都放进结果。最后插入重叠的部分*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t n = intervals.size(), cur = 0;
        for(size_t i = 0; i < n; ++i){
            if(intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
                cur++;
            }
            else if(newInterval[1] < intervals[i][0]) res.push_back(intervals[i]);
            else{
                newInterval[0] = min(newIntervals[0], intervals[i][0]);
                newInterval[1] = max(newIntervals[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;   
    }
};


15.4 Merge Intervals  (56)
Given a collection of intervals, merge all overlapping intervals.
For example, Given [1,3],[2,6],[8,10],[15,18], return [1,6],[8,10],[15,18]

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i = 1; i < n; ++i){
            if(res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};

/*可以新建一个空数组， 调用57题insert函数*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>  res;
        int n = intervals.size();
        for(int i = 0; i < n; ++i){
            res = insert(res, intervals[i]);
        }
        return res;   
    }
private:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        size_t n = intervals.size(), cur = 0;
        for(size_t i = 0; i < n; ++i){
            if(intervals[i][1] < newInterval[0]){
                res.push_back(intervals[i]);
                cur++;
            }
            else if(newInterval[1] < intervals[i][0]) res.push_back(intervals[i]);
            else{
                newInterval[0] = min(newIntervals[0], intervals[i][0]);
                newInterval[1] = max(newIntervals[1], intervals[i][1]);
            }
        }
        res.insert(res.begin() + cur, newInterval);
        return res;   
    }
};


15.5 Minimum Window Substring  (76)
Given a string S and a string T , find the minimum window in S which will contain all the characters in
T in complexity O(n).
For example, S = "ADOBECODEBANC", T = "ABC"
Minimum window is "BANC".
Note:
• If there is no such window in S that covers all characters in T , return the emtpy string "".
• If there are multiple such windows, you are guaranteed that there will always be only one unique
minimum window in S.
/*Sliding Window */
class Solution {
public:
    string minWindow(string s, string t) {
        if(s.empty() || s.empty()) return "";
        string res = "";
        vector<int> mp(128, 0);
        int left = 0, cnt = t.size(), minLen = INT_MAX;
        for(char c : t) ++mp[c];
        for(int i = 0; i < s.size(); ++i){
            if(--mp[s[i]] >= 0) --cnt;
            while(cnt == 0){
                if(minLen > i - left + 1){
                    minLen = i - left + 1;
                    res = s.substr(left, minLen);
                }
                if(++mp[s[left++]] > 0) ++cnt;
            }
        }
        return res;    
    }
};


15.6 Multiply Strings  (43)

Given two numbers represented as strings, return multiplication of the numbers as a string.
Note: The numbers can be arbitrarily large and are non-negative.
      8 9
      7 6
 ------------
      5 4
    4 8
    6 3
  5 6      
/*两数相乘得到的乘积的长度其实其实不会超过两个数字的长度之和，若 num1 长度为m，num2 长度为n，则 num1 x num2 的长度不会超过 m+n，还有就是要明白乘的时候为什么要错位，比如6乘8得到的 48 为啥要跟6乘9得到的 54 错位相加，因为8是十位上的数字，其本身相当于80，所以错开的一位实际上末尾需要补的0。还有一点需要观察出来的就是，num1 和 num2 中任意位置的两个数字相乘，得到的两位数在最终结果中的位置是确定的，比如 num1 中位置为i的数字乘以 num2 中位置为j的数字，那么得到的两位数字的位置为 i+j 和 i+j+1，明白了这些后，就可以进行错位相加了，累加出最终的结果。

由于要从个位上开始相乘，所以从 num1 和 num2 字符串的尾部开始往前遍历，分别提取出对应位置上的字符，将其转为整型后相乘。然后确定相乘后的两位数所在的位置 p1 和 p2，由于 p2 相较于 p1 是低位，所以将得到的两位数 mul 先加到 p2 位置上去，这样可能会导致 p2 位上的数字大于9，所以将十位上的数字要加到高位 p1 上去，只将余数留在 p2 位置，这样每个位上的数字都变成一位。然后要做的是从高位开始，将数字存入结果 res 中，记住 leading zeros 要跳过，最后处理下 corner case，即若结果 res 为空，则返回 "0"，否则返回结果 res，*/

class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size();
        vector<int> vals(m + n);
        for(int i = m - 1; i >= 0; --i){
            for(int j = n - 1; j >= 0; --j){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }

        for(int val : vals){
            if(!res.empty() || val != 0) res.push_back(val + '0');
        }

        return res.empty() ? "0" : res;
    }
};



15.7 Substring with Concatenation of All Words  (30)
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of
substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.
For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]
You should return the indices: [0,9].(order does not matter).

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.empty() || words.empty()) return {};
        vector<int> res;
        int n = words.size(), len = words[0].size();
        unordered_map<string, int> mp;
        for(string word : words) ++mp[word];
        for(int i = 0; i <= (int)s.size() - n * len; ++i){
            int j = 0;
            unordered_map<string, int> cnt;
            for(j = 0; j < n; ++j){
                string t = s.substr(i + j * len, len);
                if(! mp.count(t)) break;
                if(++cnt[t] > mp[t]) break;
            }
            if(j == n) res.push_back(i);
        }
        return res;
    }
};


15.8 Pascal’s Triangle  (118)
Given numRows, generate the first numRows of Pascal’s triangle.
For example, given numRows = 5,
Return
[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for(int i = 0; i < numRow; ++i){
            res[i].resize(i + 1, 1);
            for(int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
            }
        }
        return res;
    }
};

15.9 Pascal’s Triangle II  (119)
Given an index k, return the kth row of the Pascal’s triangle.
For example, given k = 3,
Return [1,3,3,1].
Note: Could you optimize your algorithm to use only O(k) extra space?

/*杨辉三角主要有下列五条性质：
杨辉三角以正整数构成，数字左右对称，每行由1开始逐渐变大，然后变小，回到1。
第n行的数字个数为n个。
第n行的第k个数字为组合数 C_{n-1}^{k-1}。
第n行数字和为 2^{n-1}。
除每行最左侧与最右侧的数字以外，每个数字等于它的左上方与右上方两个数字之和（也就是说，第n行第k个数字等于第 n-1 行的第 k-1 个数字与第k个数字的和）。这是因为有组合恒等式：C_{n}^{i}=C_{n-1}^{i-1}+C_{n-1}^{i}。可用此性质写出整个杨辉三角形。*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1);
        res[0] = 1;
        for(int i = 1; i <= rowIndex; ++i){
            for(int j = i; j >= 1; --j){
                res[j] += res[j - 1];
            }
        }
        return res;        
    }
};


15.10 Spiral Matrix (54)
Given a matrix of m × n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example, Given the following matrix:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1;
        while(true){
            for(int j = left; j <= right; ++j) res.push_back(matrix[up][j]);
            if(++up > down) break;
            for(int i = up; i <= down; ++i) res.push_back(matrix[i][right]);
            if(--right < left) break;
            for(int j = right; j >= left; --j) res.push_back(matrix[down][j]);
            if(--down < up) break;
            for(int i = down; i >= up; --i) res.push_back(matrix[i][left]);
            if(++left > right) break;
        }
        return res;
    }
};



15.11 Spiral Matrix II  (59)
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
For example, Given n = 3,
You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n));
        int begin = 0, end = n - 1;
        int num = 1;
        while(begin < end){
            for(int j = begin; j < end; ++j) res[begin][j] = num++;
            for(int i = begin; i < end; ++i) res[i][end] = num++;
            for(int j = end; j > begin; --j) res[end][j] = num++;
            for(int i = end; i > begin; --i) res[i][begin] = num++;
            ++begin;
            --end;
        }

        if(begin == end) res[begin][begin] = num;
        return res;    
    }
};


15.12 ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you
may want to display this pattern in a fixed font for better legibility)

And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:
string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        int i = 0, n = s.size();
        string res;
        vector<string> vec(numRows);
        while(i < n){
            for(int pos = 0; pos < numRows && i < n; ++pos)
                vec[pos] += s[i++];
            for(int pos = numRows - 2; pos >= 1 && i < n; --pos)
                vec[pos] += s[i++]
        }
        for(string v : vec)
            res += v;
        return res;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        int n = s.size(), pos = 0;
        bool down = true;
        string res;
        vector<string> vec(numRows);
        for(int i = 0; i < n; ++i){
            vec[pos] += s[i];
            if(down){
                ++pos;
                if(pos == numRows){
                    pos = numRows - 2;
                    down = false;
                }
            }
            else{
                --pos;
                if(pos < 0){
                    pos = 1;
                    down = true;
                }
            }
        }
        for(string v : vec) res += v;
        return res;
    }
};



15.13 Divide Two Integers  (29)
Divide two integers without using multiplication, division and mod operator.

class Solution {
public:
    int divide(int dividend, int divisor) {
        
    }
};

15.14 Text Justification


15.15 Max Points on a Line
